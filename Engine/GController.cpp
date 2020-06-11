#include "GController.h"

namespace AEngine {

	GController::GController()
	{
		std::cout << "[" << this << "]" << "GController::GController()\t" << std::endl;
		//初始化输入控制对象
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
