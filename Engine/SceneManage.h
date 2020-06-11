#pragma once
#include "IScene.h"
#include "Common.h"
#include "GController.h"
/*+--------------------------------------
* | 场景管理类 <用于派生游戏场景管理>
* +--------------------------------------
*/
namespace AEngine {

	class AHLIN_API SceneManage : public GController{
	protected:
		IScene* pScene = nullptr;		//当前场景
	public:
		virtual bool Init();
		virtual bool Update();
		virtual ~SceneManage();
		
		//设置当前播放场景
		bool SetScene(IScene* _scene);

		//获取当前场景
		IScene* GetScene();
	};


}