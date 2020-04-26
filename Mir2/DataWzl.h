#pragma once
#include "Common.h"
#include "DataWzx.h"
#include "DataBmp.h"

class DataWzl {
protected:
	char file[64] = {0};		//文件名
	WzlHeader m_WzlHeader = {};  //索引文件头部
	DataWzx* m_Wzx;
public:
	DataWzl(const char* _file);
	~DataWzl();

	void Load(int sort,DataBmp* dBmp);
};