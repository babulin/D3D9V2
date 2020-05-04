#include "GameWnd.h"

namespace AEngine {

	IGameWnd* gGameWnd;
	AEngine::IGameWnd* AEngine::CreateWnd() {
		if (gGameWnd == nullptr)
		{
			gGameWnd = new GameWnd();
		}
		return gGameWnd;
	}

	void GameWnd::SetSize(float width, float height)
	{
		this->width = width;
		this->height = height;
	}

	void GameWnd::SetTitle(wstring title)
	{
		this->title = title;
	}

	void GameWnd::Init(HINSTANCE hInstance)
	{
		OutputDebugString(L"GameWind()构造\n");
		//1、对象
		WNDCLASS wc;
		wc.cbClsExtra = 0;										//类额外的内存，通常为零
		wc.cbWndExtra = 0;										//窗口额外的内存，通常为零
		wc.hbrBackground = NULL;// (HBRUSH)GetStockObject(BLACK_BRUSH);	//设置背景
		wc.hCursor = LoadCursor(NULL, IDC_HAND);				//设置光标，如果第一个参数为NULL，代表使用系统提供的默认光标
		wc.hIcon = LoadIcon(NULL, IDC_ICON);					//LOGO
		wc.hInstance = hInstance;								//当前实例句柄，WinMain函数中形参即可
		wc.lpfnWndProc = GameWnd::WindowProc;					//窗口过程函数，回调函数，名称可以随便起
		wc.lpszClassName = title.c_str();						//指定窗口类名
		wc.lpszMenuName = NULL;									//菜单名，没有填NULL
		wc.style = 0;											//0代表默认风格

		//2、注册窗口
		RegisterClass(&wc);

		//3、计算客户区大小
		int screenW = GetSystemMetrics(SM_CXSCREEN);//获取屏幕大小
		int screenH = GetSystemMetrics(SM_CYSCREEN);//获取屏幕大小

		int mX = (screenW / 2) - (static_cast<int>(width) / 2);
		int mY = (screenH / 2) - (static_cast<int>(height) / 2);

		SetRect(&wndRect, mX, mY, static_cast<int>(width) + mX, static_cast<int>(height) + mY);
		AdjustWindowRect(&wndRect, WS_OVERLAPPEDWINDOW, false);

		//4、创建窗口
		hwnd = CreateWindow(
			title.c_str(),					//类名
			title.c_str(),					//窗口名
			WS_OVERLAPPEDWINDOW,			//显示风格  WS_OVERLAPPEDWINDOW
			wndRect.left,					//起始坐标 x CW_USEDEFAULT
			wndRect.top,					//起始坐标 y CW_USEDEFAULT
			wndRect.right - wndRect.left,	//窗口宽度 nWidth
			wndRect.bottom - wndRect.top,	//窗口高度 nHeight
			NULL,							//父窗口，NULL
			NULL,							//菜单  NULL
			hInstance,						//实例句柄，hInstance
			NULL							//其他参数   NULL
		);

		if (hwnd == NULL)
		{
			MessageBox(NULL, TEXT("创建窗口失败"), TEXT("错误提示"), MB_OK);
		}

		GetClientRect(hwnd, &clientRect);

		//5、显示和更新
		ShowWindow(hwnd, SW_SHOWDEFAULT);
		UpdateWindow(hwnd);
	}

	bool GameWnd::GetMsg()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				return false;
			}
		}
		return true;
	}


	//窗口消息处理回调
	LRESULT CALLBACK GameWnd::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{

		TCHAR buf[1024];
		switch (uMsg)
		{
		case WM_CLOSE:
			DestroyWindow(hwnd);                //触发WM_DESTROY
			break;
		case WM_DESTROY:
			PostQuitMessage(0);                  //发送退出消息
			break;
		case WM_SIZE:
		{
			if (gGameWnd)
			{
				int width = LOWORD(lParam);
				int height = HIWORD(lParam);
				gGameWnd->width = static_cast<float>(width);
				gGameWnd->height = static_cast<float>(height);
			}
			break;
		}
		case WM_LBUTTONDOWN:                      //鼠标左键按下消息
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"左键按下:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_LBUTTONUP:                      //鼠标左键弹起消息
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"左键弹起:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_RBUTTONDOWN:                      //鼠标右键按下消息
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"右键按下:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_RBUTTONUP:                      //鼠标右键弹起消息
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"右键弹起:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			break;
		}
		case WM_KEYDOWN:       //键盘消息
		{
			wsprintf(buf, L"键盘按下:%c\n", wParam);
			OutputDebugString(buf);
			break;
		}
		case WM_KEYUP:       //键盘消息
		{
			wsprintf(buf, L"键盘按下:%c\n", wParam);
			OutputDebugString(buf);
			break;
		}
		case WM_MOUSEMOVE:
		{
			//gWnd->mMouse.x = LOWORD(lParam); //取得x的坐标
			//gWnd->mMouse.y = HIWORD(lParam); //取得y的坐标
			break;
		}
		default:
			break;
		}
		//默认方式处理
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}