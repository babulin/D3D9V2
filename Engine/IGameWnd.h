#pragma once
#include <Windows.h>
#include <string>
/**+-----------------------------------------------
 * | 游戏窗口 抽象层
 * |<面向DirectX OpenGL接口>
 * +-----------------------------------------------
 */
using std::wstring;

namespace AhlinI {

	class IGameWnd {
    public:
        HWND hwnd;          //窗口句柄
        RECT wndRect;       //窗口屏幕位置
        RECT clientRect;    //客户区矩形
        float width;        //窗口宽
        float height;       //窗口高
        wstring title;      //窗口标题
        POINT mMouse;       //鼠标

    public:
        virtual void SetSize(float _width, float _height) = 0;
        virtual void SetTitle(wstring title) = 0;
        virtual void Init(HINSTANCE hInstance) = 0;
        virtual bool GetMsg() = 0;
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};

    IGameWnd* CreateWnd();
}