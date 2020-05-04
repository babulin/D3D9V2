#include "World.h"
#include "Game.h"
#include "Engine.h"
#include "Spirit.h"

Game g_game;
Spirit* g_spirit1;
bool World::Init()
{
	g_spirit1 = new Spirit(L"2.png");
	g_spirit1->Load();

	return true;
}

bool World::Update()
{
	//ÇÐ»»³¡¾°
	if (GetAsyncKeyState('1'))
	{
		delete g_spirit1;
		g_spirit1 = nullptr;

		//ÇÐ»»µ½World
		Engine* engine = CreateEngine(AGE_VERSION);
		g_game.Init();
		engine->SetCallBack(&g_game);
	}
	return true;
}

bool World::Show()
{
	g_spirit1->Show(800.0f, 600.0f, 100.0f, 100.0f);

	return true;
}
