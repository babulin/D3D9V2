#pragma once
#include "Common.h"
#include "DataWzx.h"
#include "DataBmp.h"

class DataWzl {
protected:
	char file[64] = {0};		//�ļ���
	WzlHeader m_WzlHeader = {};  //�����ļ�ͷ��
	DataWzx* m_Wzx;
public:
	DataWzl(const char* _file);
	~DataWzl();

	void Load(int sort,DataBmp* dBmp);
};