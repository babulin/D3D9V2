#pragma once
#include <Windows.h>
#include <string>
/**+-----------------------------------------------
 * | ��Ϸ���� �����
 * |<����DirectX OpenGL�ӿ�>
 * +-----------------------------------------------
 */
using std::wstring;

namespace AhlinI {

	class IGameWnd {
    public:
        HWND hwnd;          //���ھ��
        RECT wndRect;       //������Ļλ��
        RECT clientRect;    //�ͻ�������
        float width;        //���ڿ�
        float height;       //���ڸ�
        wstring title;      //���ڱ���
        POINT mMouse;       //���

    public:
        virtual void SetSize(float _width, float _height) = 0;
        virtual void SetTitle(wstring title) = 0;
        virtual void Init(HINSTANCE hInstance) = 0;
        virtual bool GetMsg() = 0;
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};

    IGameWnd* CreateWnd();
}