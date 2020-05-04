#pragma once
#include "Common.h"
/**+-----------------------------------------------
 * | �쳣���� �����
 * |<����>
 * +-----------------------------------------------
 */
namespace AEngine {

    //�쳣��
    enum ExCode
    {
        EX_FAIL = 0,	//����
        EX_OK = 1,		//��ȷ
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