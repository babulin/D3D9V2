#include "DXInput.h"

namespace AEngine {

	//��̬��Ա��ʼ��
	DXInput* DXInput::g_pDinput = nullptr;

	//DI����ģʽ
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
			MessageBox(nullptr, L"����DXInputʧ��", L"��Ϣ��ʾ", MB_OK);
		}

		g_pDirectInput->CreateDevice(GUID_SysKeyboard, &g_pKeyboardDevice, NULL);
		//pDInput8->EnumDevices()

		// �������ݸ�ʽ��Э������
		g_pKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
		g_pKeyboardDevice->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
		g_pKeyboardDevice->Acquire();

		return true;
	}

	void DXInput::Read()
	{
		// ��ȡ��������
		::ZeroMemory(g_pKeyStateBuffer, sizeof(g_pKeyStateBuffer));
		ReadDevice(g_pKeyboardDevice, (LPVOID)g_pKeyStateBuffer, sizeof(g_pKeyStateBuffer));
	}

	//--------------------------------------------------------------------------------------
	// Name: ReadDevice();
	// Desc: ��ȡ�豸����������
	//--------------------------------------------------------------------------------------
	bool DXInput::ReadDevice(IDirectInputDevice8* pDIDevice, void* pBuffer, long lSize)
	{
		HRESULT hr;
		while (true)
		{
			pDIDevice->Poll();              // ��ѯ�豸
			pDIDevice->Acquire();           // ��ȡ�豸�Ŀ���Ȩ
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
