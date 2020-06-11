#pragma once
#include "DXInput.h"
/*+--------------------------------------
* | 场景管理类 <用于派生游戏场景管理>
* +--------------------------------------
*/

namespace AEngine {

	class AHLIN_API GController{
	protected:
		DXInput* g_pKeyboard = nullptr;	//输入控制
	public:
		GController();
		//获取当前按钮
		bool GetKeyState(int key);
	};


}