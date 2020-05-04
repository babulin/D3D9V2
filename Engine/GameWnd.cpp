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
		OutputDebugString(L"GameWind()����\n");
		//1������
		WNDCLASS wc;
		wc.cbClsExtra = 0;										//�������ڴ棬ͨ��Ϊ��
		wc.cbWndExtra = 0;										//���ڶ�����ڴ棬ͨ��Ϊ��
		wc.hbrBackground = NULL;// (HBRUSH)GetStockObject(BLACK_BRUSH);	//���ñ���
		wc.hCursor = LoadCursor(NULL, IDC_HAND);				//���ù�꣬�����һ������ΪNULL������ʹ��ϵͳ�ṩ��Ĭ�Ϲ��
		wc.hIcon = LoadIcon(NULL, IDC_ICON);					//LOGO
		wc.hInstance = hInstance;								//��ǰʵ�������WinMain�������βμ���
		wc.lpfnWndProc = GameWnd::WindowProc;					//���ڹ��̺������ص����������ƿ��������
		wc.lpszClassName = title.c_str();						//ָ����������
		wc.lpszMenuName = NULL;									//�˵�����û����NULL
		wc.style = 0;											//0����Ĭ�Ϸ��

		//2��ע�ᴰ��
		RegisterClass(&wc);

		//3������ͻ�����С
		int screenW = GetSystemMetrics(SM_CXSCREEN);//��ȡ��Ļ��С
		int screenH = GetSystemMetrics(SM_CYSCREEN);//��ȡ��Ļ��С

		int mX = (screenW / 2) - (static_cast<int>(width) / 2);
		int mY = (screenH / 2) - (static_cast<int>(height) / 2);

		SetRect(&wndRect, mX, mY, static_cast<int>(width) + mX, static_cast<int>(height) + mY);
		AdjustWindowRect(&wndRect, WS_OVERLAPPEDWINDOW, false);

		//4����������
		hwnd = CreateWindow(
			title.c_str(),					//����
			title.c_str(),					//������
			WS_OVERLAPPEDWINDOW,			//��ʾ���  WS_OVERLAPPEDWINDOW
			wndRect.left,					//��ʼ���� x CW_USEDEFAULT
			wndRect.top,					//��ʼ���� y CW_USEDEFAULT
			wndRect.right - wndRect.left,	//���ڿ�� nWidth
			wndRect.bottom - wndRect.top,	//���ڸ߶� nHeight
			NULL,							//�����ڣ�NULL
			NULL,							//�˵�  NULL
			hInstance,						//ʵ�������hInstance
			NULL							//��������   NULL
		);

		if (hwnd == NULL)
		{
			MessageBox(NULL, TEXT("��������ʧ��"), TEXT("������ʾ"), MB_OK);
		}

		GetClientRect(hwnd, &clientRect);

		//5����ʾ�͸���
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


	//������Ϣ����ص�
	LRESULT CALLBACK GameWnd::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
	{

		TCHAR buf[1024];
		switch (uMsg)
		{
		case WM_CLOSE:
			DestroyWindow(hwnd);                //����WM_DESTROY
			break;
		case WM_DESTROY:
			PostQuitMessage(0);                  //�����˳���Ϣ
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
		case WM_LBUTTONDOWN:                      //������������Ϣ
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"�������:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_LBUTTONUP:                      //������������Ϣ
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"�������:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_RBUTTONDOWN:                      //����Ҽ�������Ϣ
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"�Ҽ�����:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			OutputDebugString(buf);
			break;
		}
		case WM_RBUTTONUP:                      //����Ҽ�������Ϣ
		{
			gGameWnd->mMouse.x = LOWORD(lParam);
			gGameWnd->mMouse.y = HIWORD(lParam);
			wsprintf(buf, L"�Ҽ�����:%d,%d\n", gGameWnd->mMouse.x, gGameWnd->mMouse.y);
			break;
		}
		case WM_KEYDOWN:       //������Ϣ
		{
			wsprintf(buf, L"���̰���:%c\n", wParam);
			OutputDebugString(buf);
			break;
		}
		case WM_KEYUP:       //������Ϣ
		{
			wsprintf(buf, L"���̰���:%c\n", wParam);
			OutputDebugString(buf);
			break;
		}
		case WM_MOUSEMOVE:
		{
			//gWnd->mMouse.x = LOWORD(lParam); //ȡ��x������
			//gWnd->mMouse.y = HIWORD(lParam); //ȡ��y������
			break;
		}
		default:
			break;
		}
		//Ĭ�Ϸ�ʽ����
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}