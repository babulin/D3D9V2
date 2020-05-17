#include "DataWzl.h"

DataWzl::DataWzl(const char* _file)
{
	std::cout << "[" << this << "]" << "DataWzl::DataWzl()\t" << std::endl;

	//图片
	strcpy_s(file, strlen(_file) + 1, _file);
	strcat_s(file, sizeof(file), ".wzl");

	//加载索引文件
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
	//设置当前序号
	dBmp->sort = sort;

	FILE* fp;

	//读取wzl
	fopen_s(&fp, file, "r+b");
	if (fp == NULL) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzl] %s 加载失败\n", file);
		std::cout << buf << std::endl;
		return;
	}

	//根据状态 加载图片
	int offset = (*m_Wzx)[sort];
	if (offset == 0) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzl] %s;offset:%d 加载失败\n", file,offset);
		std::cout << buf << std::endl;
		return;
	}

	//指向图片结构体头部位置
	fseek(fp, offset, SEEK_SET);

	//读取对应图片头部结构
	fread(&(dBmp->m_BmpInfo), sizeof(WzlBmpInfo), 1, fp);

	//偏移+图片结构体[指针指向数据]
	fseek(fp, offset + sizeof(WzlBmpInfo), SEEK_SET);

	//源数据
	ULONG srcSize = dBmp->m_BmpInfo.size;
	BYTE* srcBuffer = nullptr;
	srcBuffer = new BYTE[srcSize];

	//读取图片的数据
	fread(srcBuffer, srcSize, 1, fp);

	//图片实际大小 (5 = 16位图 D3DFMT_R5G6B5[2倍数据大小对齐])(3 = 32位图 D3DFMT_A8R8G8B8)
	ULONG dstSize = dBmp->m_BmpInfo.width * dBmp->m_BmpInfo.height * (dBmp->m_BmpInfo.pixelFormat == 5 ? 2 : 1);

	//使用zlib解压数据
	dBmp->p_Data = new BYTE[dstSize];

	//获得位图数据[与调色板对应的位置数据] //这句是，对909 的所有数据进行解压，得到的位图数据
	uncompress(dBmp->p_Data, &dstSize, srcBuffer, srcSize);

	//清除源数据缓冲区
	delete[] srcBuffer;

	fclose(fp);

	//输出调试信息
	char buf[MSG_SIZE] = { 0 };
	sprintf_s(buf, "[DataWzl] %s %d [%d x %d] 加载成功!", file, sort, dBmp->m_BmpInfo.width, dBmp->m_BmpInfo.height);
	std::cout << "[" << this << "]" << buf << std::endl;
}
