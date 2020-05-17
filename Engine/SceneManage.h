#pragma once
#include "IScene.h"
#include "Common.h"
/*+--------------------------------------
* | ���������� <����������Ϸ��������>
* +--------------------------------------
*/

namespace AEngine {

	class AHLIN_API SceneManage {
	protected:
		IScene* pScene;			//��ǰ����
	public:
		virtual bool Init();
		virtual bool Update();
		virtual ~SceneManage(){
			if (pScene != nullptr)
			{
				//�������ɾ�����һ������
				delete pScene;
			}
		}

		bool SetScene(IScene* _scene);

		//��ȡ��ǰ����
		IScene* GetScene();
	};


}