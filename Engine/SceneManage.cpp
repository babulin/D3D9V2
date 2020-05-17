#include "SceneManage.h"
#include <iostream>
namespace AEngine {

	bool SceneManage::Init()
	{
		std::cout << "[" << this << "]" << "SceneManage::Init()\t" << std::endl;
		return true;
	}

	bool SceneManage::Update()
	{
		return true;
	}

	bool SceneManage::SetScene(IScene* _scene)
	{
		if (pScene == _scene)
		{
			return true;
		}

		if (_scene != nullptr)
		{
			//����һ��
			_scene->Init();
			_scene->Update();
			_scene->Show();
		}

		if (pScene != nullptr)
		{
			//����ǰ��һ������
			delete pScene;
		}

		//��ֵ��ǰ����
		pScene = _scene;

		return true;
	}

	//��ȡ��ǰ����
	IScene* SceneManage::GetScene()
	{
		return pScene;
	}
}
