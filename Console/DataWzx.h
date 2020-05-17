#pragma once
#include "DataConfig.h"
/*+---------------------------------------------
 *| Wzx 索引文件资源类
 *| <time:2020/04/11>
 *+---------------------------------------------
 */

class DataWzx
{
private:
    char file[64] = {0};       //文件名
    WzxHeader m_WzxHeader = {};  //索引文件头部
    int* p_WzxOffset = nullptr;       //存储索引指针
public:
	DataWzx(const char* _file);
	~DataWzx();

    void Load();
    int operator[](int sort);

private:

};