#include "DInput.h"

namespace AEngine {

	DInput::DInput()
	{
	}

	void DInput::Init()
	{
		HINSTANCE hInstance = GetModuleHandle(nullptr);
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&pDInput8, nullptr))) {
			MessageBox(nullptr, L"����DInputʧ��", L"��Ϣ��ʾ", MB_OK);
		}

		//pDInput8->EnumDevices()
	}
}
