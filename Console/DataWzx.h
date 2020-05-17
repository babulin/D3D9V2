#pragma once
#include "DataConfig.h"
/*+---------------------------------------------
 *| Wzx �����ļ���Դ��
 *| <time:2020/04/11>
 *+---------------------------------------------
 */

class DataWzx
{
private:
    char file[64] = {0};       //�ļ���
    WzxHeader m_WzxHeader = {};  //�����ļ�ͷ��
    int* p_WzxOffset = nullptr;       //�洢����ָ��
public:
	DataWzx(const char* _file);
	~DataWzx();

    void Load();
    int operator[](int sort);

private:

};