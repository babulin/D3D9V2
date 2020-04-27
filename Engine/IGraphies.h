#pragma once
#include "GError.h"
/**+-----------------------------------------------
 * | 图形API抽象层
 * |<面向DirectX OpenGL接口>
 * +-----------------------------------------------
 */
namespace AhlinI {

    class IGraphies {
    protected:

    public:
        //初始化图形接口
        virtual ExCode Init() = 0;

        //
    };
}