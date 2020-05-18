#include "DInput.h"

namespace AEngine {

	DInput::DInput()
	{
	}

	void DInput::Init()
	{
		HINSTANCE hInstance = GetModuleHandle(nullptr);
		if (FAILED(DirectInput8Create(hInstance, 0x0800, IID_IDirectInput8, (LPVOID*)&pDInput8, nullptr))) {
			MessageBox(nullptr, L"创建DInput失败", L"消息提示", MB_OK);
		}

		//pDInput8->EnumDevices()
	}
}
