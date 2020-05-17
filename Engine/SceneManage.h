#pragma once
#include "IScene.h"
#include "Common.h"
/*+--------------------------------------
* | 场景管理类 <用于派生游戏场景管理>
* +--------------------------------------
*/

namespace AEngine {

	class AHLIN_API SceneManage {
	protected:
		IScene* pScene;			//当前场景
	public:
		virtual bool Init();
		virtual bool Update();
		virtual ~SceneManage(){
			if (pScene != nullptr)
			{
				//程序结束删除最后一个场景
				delete pScene;
			}
		}

		bool SetScene(IScene* _scene);

		//获取当前场景
		IScene* GetScene();
	};


}