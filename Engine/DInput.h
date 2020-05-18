#pragma once
#include <dinput.h>
namespace AEngine {

	class DInput {
	protected:
		LPDIRECTINPUT8 pDInput8 = nullptr;
	public:
		DInput();
		void Init();
	};
}