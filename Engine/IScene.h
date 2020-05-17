#pragma once
/*+--------------------------------------
* | 场景基类 <用于派生游戏场景类>
* +--------------------------------------
*/
namespace AEngine {
	class IScene {
	public:
		virtual bool Init() = 0;
		virtual bool Update() = 0;
		virtual bool Show() = 0;
		virtual ~IScene() {};
	};
}