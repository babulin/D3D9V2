#pragma once
/*+--------------------------------------
* | 游戏类 <用于管理游戏开发>
* +--------------------------------------
*/
namespace AEngine{
	class IGame {
	public:
		virtual bool Init();
		virtual bool Update();
		virtual bool Show();
		bool SetSence();
		virtual ~IGame() {};
	};
}