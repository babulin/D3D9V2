#pragma once
#include <Windows.h>
#include <string>
using std::wstring;

namespace AEngine {
	class GameWnd {
	public:
		HWND hwnd;          //窗口句柄
		RECT wndRect;       //窗口屏幕位置
		RECT clientRect;    //客户区矩形
		int width;			//窗口宽
		int height;			//窗口高
		wstring title;      //窗口标题
		POINT mMouse;       //鼠标
		HINSTANCE hInstance;//实例句柄
		static GameWnd* gGameWnd;//单例对象
	private:
		GameWnd();
	public:
		//static
		static GameWnd* CreateWnd();	//获得单例

		//public
		void SetSize(int width, int height);	//设置大小
		void SetTitle(wstring title);			//设置标题
		bool Create();							//创建窗口
		void Update();							//更新显示
		bool GetMsg();							//消息处理
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		~GameWnd();								//析构
	};
}