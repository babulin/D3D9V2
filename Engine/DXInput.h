#pragma once
#include "Common.h"

namespace AEngine {

	class AHLIN_API DXInput {
	private:
		static DXInput* g_pDinput;
	protected:
		LPDIRECTINPUT8			g_pDirectInput;
		LPDIRECTINPUTDEVICE8	g_pKeyboardDevice;
		char                    g_pKeyStateBuffer[256] = { 0 };
	private:
		DXInput();
		bool ReadDevice(IDirectInputDevice8* pDIDevice, void* pBuffer, long lSize);
	public:
		//static
		static DXInput* GetInstance();	//»ñÈ¡µ¥Àý

		bool Init(HINSTANCE hInstance, HWND hwnd);
		void Read();
		bool GetKeyState(int key);
		~DXInput();
	};

}