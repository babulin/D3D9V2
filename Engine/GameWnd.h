#pragma once
#include "IGameWnd.h"

namespace AhlinI {
	class GameWnd : public IGameWnd {
	public:
		GameWnd() {
			hwnd = nullptr;
			wndRect = {0,0,0,0};
			width = 800.0f;
			height = 600.0f;
			title = L"DX9 v2.1";
		};
		virtual void SetSize(float width,float height);
		virtual void SetTitle(wstring title);
		virtual void Init(HINSTANCE hInstance);
		virtual bool GetMsg();
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}