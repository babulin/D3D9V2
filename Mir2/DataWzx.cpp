#include "DataWzx.h"
#include "Log.h"

DataWzx::DataWzx(const char* _file)
{
	Log::Debug("DataWzx()构造\n");
	//图片
	strcpy_s(file, strlen(_file) + 1, _file);
	strcat_s(file, sizeof(file), ".wzx");
}

DataWzx::~DataWzx()
{

	if (p_WzxOffset != nullptr){
		delete[] p_WzxOffset;
		p_WzxOffset = nullptr;
	}
	Log::Debug("~DataWzx()析构\n");
}

void DataWzx::Load()
{
	FILE* fp;

	//打开
	fopen_s(&fp, file, "r+b");
	if (fp == NULL) {
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzx] %s 加载失败\n", file);
		Log::Debug(buf);
		return;
	}

	//取出wzx头部结构体
	fread(&m_WzxHeader, sizeof(WzxHeader), 1, fp);

	//偏移头部信息
	fseek(fp, sizeof(WzxHeader), SEEK_SET);
	
	//初始化大小
	p_WzxOffset = new int[m_WzxHeader.imageCount];

	//读取
	fread(p_WzxOffset, sizeof(int), m_WzxHeader.imageCount, fp);

	fclose(fp);

	//输出调试信息
	if (HAS_DEBUG)
	{
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[DataWzx] %s %d 加载成功！\n", file,m_WzxHeader.imageCount);
		Log::Debug(buf);
	}
}

int DataWzx::operator[](int sort)
{
	if (sort > m_WzxHeader.imageCount){
		//访问的序号已经超出了
		return 0;
	}

	return p_WzxOffset[sort];
}
