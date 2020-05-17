#include "MScene.h"
#include <iostream>
//初始化场景进度
GAME_SCENE MScene::GameProgress = GAME_SCENE::GS_Login;

MScene::MScene()
{

}

bool MScene::Init()
{
	std::cout << "[" << this << "]" << "MScene::Init()\t" << std::endl;

	//场景对象
	mSLogin = new SceneLogin();

	return true;
}

//场景更新
bool MScene::Update()
{
	if (GetAsyncKeyState('1'))
	{
		//切换到角色
		mSelRole = new SceneSelRole();
		GameProgress = GAME_SCENE::GS_SelectRole;
	}
	if (GetAsyncKeyState('2'))
	{
		mSLogin = new SceneLogin();
		GameProgress = GAME_SCENE::GS_Login;
	}

	switch (GameProgress)
	{
		case GAME_SCENE::GS_Login:
			SetScene(mSLogin);
			break;
		case GAME_SCENE::GS_SelectRole:
			SetScene(mSelRole);
			//SetScene(nullptr);
			break;
		default:
			break;
	}
	return true;
}

MScene::~MScene()
{
	std::cout << "[X]" << "[" << this << "]" << "MScene::~MScene()\t" << std::endl;
}
