#pragma once
#include "Common.h"
/**+-----------------------------------------------
 * | 异常处理 抽象层
 * |<基类>
 * +-----------------------------------------------
 */
namespace AEngine {

    //异常码
    enum ExCode
    {
        EX_FAIL = 0,	//错误
        EX_OK = 1,		//正确
    };

    class AHLIN_API GError{
    protected:
        const char* msg;
        int code;
    public:
        GError(int code,const char* msg);
        const char* GetMsg();
    };
}