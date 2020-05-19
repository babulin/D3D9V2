#pragma once
#include <dinput.h>
#pragma comment(lib,"dinput8.lib")//使用DirectInput必须包含的头文件，注意这里有8
namespace AEngine {

	class DInput {
	protected:
		LPDIRECTINPUT8 pDInput8 = nullptr;
	public:
		DInput();
		void Init();
	};
}