#include "DataWzl.h"

DataWzl::DataWzl(const char* _file)
{
	std::cout << "[" << this << "]" << "DataWzl::DataWzl()\t" << std::endl;

	//ͼƬ
	strcpy_s(file, strlen(_file) + 1, _file);
	strcat_s(file, sizeof(file), ".wzl");

	//���������ļ�
	m_Wzx = new DataWzx(_file);
	m_Wzx->Load();
}

DataWzl::~DataWzl()
{
	if (m_Wzx != nullptr)
	{
		delete m_Wzx;
	}

	std::cout << "[X]" << "[" << this << "]" << "DataWzl::~DataWzl()\t" << std::endl;
}

void DataWzl::Load(int sort, DataBmp* dBmp)
{
	//���õ�ǰ���
	dBmp->sort = sort;

	FILE* fp;

	//��ȡwzl
	fopen_s(&fp, file, "r+b");
	if (fp == NULL) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzl] %s ����ʧ��\n", file);
		std::cout << buf << std::endl;
		return;
	}

	//����״̬ ����ͼƬ
	int offset = (*m_Wzx)[sort];
	if (offset == 0) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzl] %s;offset:%d ����ʧ��\n", file,offset);
		std::cout << buf << std::endl;
		return;
	}

	//ָ��ͼƬ�ṹ��ͷ��λ��
	fseek(fp, offset, SEEK_SET);

	//��ȡ��ӦͼƬͷ���ṹ
	fread(&(dBmp->m_BmpInfo), sizeof(WzlBmpInfo), 1, fp);

	//ƫ��+ͼƬ�ṹ��[ָ��ָ������]
	fseek(fp, offset + sizeof(WzlBmpInfo), SEEK_SET);

	//Դ����
	ULONG srcSize = dBmp->m_BmpInfo.size;
	BYTE* srcBuffer = nullptr;
	srcBuffer = new BYTE[srcSize];

	//��ȡͼƬ������
	fread(srcBuffer, srcSize, 1, fp);

	//ͼƬʵ�ʴ�С (5 = 16λͼ D3DFMT_R5G6B5[2�����ݴ�С����])(3 = 32λͼ D3DFMT_A8R8G8B8)
	ULONG dstSize = dBmp->m_BmpInfo.width * dBmp->m_BmpInfo.height * (dBmp->m_BmpInfo.pixelFormat == 5 ? 2 : 1);

	//ʹ��zlib��ѹ����
	dBmp->p_Data = new BYTE[dstSize];

	//���λͼ����[���ɫ���Ӧ��λ������] //����ǣ���909 ���������ݽ��н�ѹ���õ���λͼ����
	uncompress(dBmp->p_Data, &dstSize, srcBuffer, srcSize);

	//���Դ���ݻ�����
	delete[] srcBuffer;

	fclose(fp);

	//���������Ϣ
	char buf[MSG_SIZE] = { 0 };
	sprintf_s(buf, "[DataWzl] %s %d [%d x %d] ���سɹ�!", file, sort, dBmp->m_BmpInfo.width, dBmp->m_BmpInfo.height);
	std::cout << "[" << this << "]" << buf << std::endl;
}
