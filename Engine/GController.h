#pragma once
#include "DXInput.h"
/*+--------------------------------------
* | ���������� <����������Ϸ��������>
* +--------------------------------------
*/

namespace AEngine {

	class AHLIN_API GController{
	protected:
		DXInput* g_pKeyboard = nullptr;	//�������
	public:
		GController();
		//��ȡ��ǰ��ť
		bool GetKeyState(int key);
	};


}