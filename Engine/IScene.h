#pragma once
#include "GController.h"
/*+--------------------------------------
* | �������� <����������Ϸ������>
* +--------------------------------------
*/
namespace AEngine {
	class IScene : public GController{
	public:
		virtual bool Init() = 0;
		virtual bool Update() = 0;
		virtual bool Show() = 0;
		virtual ~IScene() {};
	};
}