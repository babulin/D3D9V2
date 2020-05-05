#pragma once
#include "IGameWnd.h"
#include <iostream>

namespace AEngine {
	class GameWnd : public IGameWnd {
	public:
		GameWnd();
		~GameWnd();
		virtual void SetSize(float width,float height);
		virtual void SetTitle(wstring title);
		virtual void Init(HINSTANCE hInstance);
		virtual bool GetMsg();
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};
}