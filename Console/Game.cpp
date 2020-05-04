#include "Game.h"
#include "World.h"
#include "Spirit.h"
#include "Engine.h"
#include <Windows.h>

World g_world;
Spirit* g_spirit;
bool Game::Init()
{
	//初始化一些资源
	g_spirit = new Spirit(L"1.png");
	g_spirit->Load();

	return true;
}

bool Game::Update()
{
	//更新数据

	//切换场景
	if (GetAsyncKeyState('1'))
	{
		delete g_spirit;
		g_spirit = nullptr;

		//切换到World
		Engine* engine = CreateEngine(AGE_VERSION);
		g_world.Init();
		engine->SetCallBack(&g_world);
	}

	return true;
}

bool Game::Show()
{
	//显示

	if (g_spirit != nullptr)
	{
		g_spirit->Show(1024.0f,768.0f,0.0f,0.0f);
	}

	return true;
}