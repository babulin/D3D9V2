#include "DXInput.h"

namespace AEngine {

	//静态成员初始化
	DXInput* DXInput::g_pDinput = nullptr;

	//DI单例模式
	DXInput* DXInput::GetInstance()
	{
		if (g_pDinput == nullptr)
		{
			g_pDinput = new DXInput();
		}
		return g_pDinput;
	}

	DXInput::DXInput()
	{
		std::cout << "[" << this << "]" << "DXInput::DXInput()\t" << std::endl;
	}

	bool DXInput::Init(HINSTANCE hInstance,HWND hwnd)
	{
		//HINSTANCE hInstance = GetModuleHandle(nullptr);
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pDirectInput, nullptr))) {
			MessageBox(nullptr, L"创建DXInput失败", L"消息提示", MB_OK);
		}

		g_pDirectInput->CreateDevice(GUID_SysKeyboard, &g_pKeyboardDevice, NULL);
		//pDInput8->EnumDevices()

		// 设置数据格式和协作级别
		g_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
		g_pKeyboardDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
		g_pKeyboardDevice->Acquire();

		return true;
	}

	void DXInput::Read()
	{
		// 读取键盘输入
		::ZeroMemory(g_pKeyStateBuffer, sizeof(g_pKeyStateBuffer));
		ReadDevice(g_pKeyboardDevice, (LPVOID)g_pKeyStateBuffer, sizeof(g_pKeyStateBuffer));
	}

	//--------------------------------------------------------------------------------------
	// Name: ReadDevice();
	// Desc: 读取设备的输入数据
	//--------------------------------------------------------------------------------------
	bool DXInput::ReadDevice(IDirectInputDevice8* pDIDevice, void* pBuffer, long lSize)
	{
		HRESULT hr;
		while (true)
		{
			pDIDevice->Poll();              // 轮询设备
			pDIDevice->Acquire();           // 获取设备的控制权
			if (SUCCEEDED(hr = pDIDevice->GetDeviceState(lSize, pBuffer))) break;
			if (hr != DIERR_INPUTLOST || hr != DIERR_NOTACQUIRED) return FALSE;
			if (FAILED(pDIDevice->Acquire())) return FALSE;
		}
		return true;
	}


	bool DXInput::GetKeyState(int key)
	{
		if (g_pKeyStateBuffer[key] & 0x80) {
			return true;
		}
		return false;
	}

	DXInput::~DXInput()
	{
		std::cout << "[X]" << "[" << this << "]" << "DXInput::~DXInput()" << std::endl;
		g_pDirectInput->Release();
		g_pKeyboardDevice->Release();
	}
}
