#pragma once
#include <dinput.h>
#pragma comment(lib,"dinput8.lib")//ʹ��DirectInput���������ͷ�ļ���ע��������8
namespace AEngine {

	class DInput {
	protected:
		LPDIRECTINPUT8 pDInput8 = nullptr;
	public:
		DInput();
		void Init();
	};
}