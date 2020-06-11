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

	SceneManage::~SceneManage()
	{
		if (pScene != nullptr)
		{
			//程序结束删除最后一个场景
			delete pScene;
		}
	}

	bool SceneManage::SetScene(IScene* _scene)
	{
		if (pScene == _scene)
		{
			return true;
		}

		if (_scene != nullptr)
		{
			//调用一次
			_scene->Init();
			_scene->Update();
			_scene->Show();
		}

		if (pScene != nullptr)
		{
			//清理当前上一个场景
			delete pScene;
		}

		//赋值当前场景
		pScene = _scene;

		return true;
	}

	//获取当前场景
	IScene* SceneManage::GetScene()
	{
		return pScene;
	}
}
