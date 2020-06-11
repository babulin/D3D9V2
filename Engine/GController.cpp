#include "GController.h"

namespace AEngine {

	GController::GController()
	{
		std::cout << "[" << this << "]" << "GController::GController()\t" << std::endl;
		//��ʼ��������ƶ���
		g_pKeyboard = DXInput::GetInstance();
	}

	bool GController::GetKeyState(int key)
	{
		if (g_pKeyboard == nullptr)
		{
			return false;
		}
		return g_pKeyboard->GetKeyState(key);
	}
}
