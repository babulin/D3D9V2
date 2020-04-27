#pragma once
#include <Windows.h>
/**+-----------------------------------------------
 * | 游戏窗口 抽象层
 * |<面向DirectX OpenGL接口>
 * +-----------------------------------------------
 */
namespace AhlinI {

	class IGameWnd {
    protected:
        HWND hwnd;
        float width;
        float height;
    public:
        virtual void CreateWnd() = 0;
        virtual void SetSize(float _width, float _height) = 0;
	};
}