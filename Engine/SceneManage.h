#pragma once
#include "IScene.h"
#include "Common.h"
#include "GController.h"
/*+--------------------------------------
* | ���������� <����������Ϸ��������>
* +--------------------------------------
*/
namespace AEngine {

	class AHLIN_API SceneManage : public GController{
	protected:
		IScene* pScene = nullptr;		//��ǰ����
	public:
		virtual bool Init();
		virtual bool Update();
		virtual ~SceneManage();
		
		//���õ�ǰ���ų���
		bool SetScene(IScene* _scene);

		//��ȡ��ǰ����
		IScene* GetScene();
	};


}