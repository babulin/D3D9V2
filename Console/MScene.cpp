#include "MScene.h"
#include <iostream>
#include "DXInput.h"
//初始化场景进度
GAME_SCENE MScene::GameProgress = GAME_SCENE::GS_Login;
static bool kBtn1 = true;
static bool kBtn2 = true;
static bool kBtn3 = true;

DXInput* g_pKeyboard;
MScene::MScene()
{

}

bool MScene::Init()
{
	std::cout << "[" << this << "]" << "MScene::Init()\t" << std::endl;

	//场景对象
	mSLogin = new SceneLogin();

	//获得输入
	g_pKeyboard = DXInput::GetInstance();

	return true;
}

//场景更新
bool MScene::Update()
{
	SetKey();

	switch (GameProgress)
	{
		case GAME_SCENE::GS_Login:
			SetScene(mSLogin);
			break;
		case GAME_SCENE::GS_SelectRole:
			SetScene(mSelRole);
			//SetScene(nullptr);
			break;
		case GAME_SCENE::GS_World:
			SetScene(mWorld);
			//SetScene(nullptr);
			break;
		default:
			break;
	}
	return true;
}

void MScene::SetKey() {
	if (g_pKeyboard->GetKeyState(DIK_1))
	{
		if (kBtn1)
		{
			//登陆界面
			mSLogin = new SceneLogin();
			GameProgress = GAME_SCENE::GS_Login;
			kBtn1 = false;
		}
	}
	else if (!kBtn1)
	{
		kBtn1 = true;
	}

	if (g_pKeyboard->GetKeyState(DIK_2))
	{
		if (kBtn2)
		{
			//切换到角色
			mSelRole = new SceneSelRole();
			GameProgress = GAME_SCENE::GS_SelectRole;
			kBtn2 = false;

		}
	}
	else if (!kBtn2)
	{
		kBtn2 = true;
	}

	if (g_pKeyboard->GetKeyState(DIK_3))
	{
		if (kBtn3)
		{
			//游戏世界
			mWorld = new SceneWorld();
			GameProgress = GAME_SCENE::GS_World;
			kBtn3 = false;
		}
	}
	else if (!kBtn3)
	{
		kBtn3 = true;
	}
}

MScene::~MScene()
{
	std::cout << "[X]" << "[" << this << "]" << "MScene::~MScene()\t" << std::endl;
}
