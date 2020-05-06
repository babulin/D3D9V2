#include "Game.h"
#include "World.h"
#include "Spirit.h"
#include "Engine.h"
#include <Windows.h>

Spirit* g_spirit;
bool Game::Init()
{
	std::cout << "[" << this << "]" << "Game::Init()" << std::endl;

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
		Engine* engine = Engine::CreateEngine(AGE_VERSION);
		World* g_world = new World();
		g_world->Init();
		engine->SetGame(g_world);

		delete this;
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