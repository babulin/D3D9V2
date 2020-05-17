#include "DataWzx.h"

DataWzx::DataWzx(const char* _file)
{
	std::cout << "[" << this << "]" << "DataWzx::DataWzx()\t" << std::endl;
	//ͼƬ
	strcpy_s(file, strlen(_file) + 1, _file);
	strcat_s(file, sizeof(file), ".wzx");
}

DataWzx::~DataWzx()
{

	if (p_WzxOffset != nullptr){
		delete[] p_WzxOffset;
		p_WzxOffset = nullptr;
	}
	std::cout << "[X]" << "[" << this << "]" << "DataWzx::~DataWzx()\t" << std::endl;
}

void DataWzx::Load()
{
	FILE* fp;

	//��
	fopen_s(&fp, file, "r+b");
	if (fp == NULL) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzx] %s ����ʧ��\n", file);
		std::cout << buf << std::endl;
		return;
	}

	//ȡ��wzxͷ���ṹ��
	fread(&m_WzxHeader, sizeof(WzxHeader), 1, fp);

	//ƫ��ͷ����Ϣ
	fseek(fp, sizeof(WzxHeader), SEEK_SET);
	
	//��ʼ����С
	p_WzxOffset = new int[m_WzxHeader.imageCount];

	//��ȡ
	fread(p_WzxOffset, sizeof(int), m_WzxHeader.imageCount, fp);

	fclose(fp);

	//���������Ϣ
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzx] %s %d ���سɹ�!", file,m_WzxHeader.imageCount);
		std::cout << "[" << this << "]" << buf << std::endl;
}

int DataWzx::operator[](int sort)
{
	if (sort > m_WzxHeader.imageCount){
		//���ʵ�����Ѿ�������
		return 0;
	}

	return p_WzxOffset[sort];
}
