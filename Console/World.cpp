#include "World.h"
#include "Game.h"
#include "Engine.h"
#include "Spirit.h"


Spirit* g_spirit1;
bool World::Init()
{
	std::cout << "[" << this << "]" << "World::Init()" << std::endl;
	g_spirit1 = new Spirit(L"2.png",L"1.png");
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
		Engine* engine = Engine::CreateEngine(AGE_VERSION);
		Game* g_game = new Game();
		g_game->Init();
		engine->SetGame(g_game);

		delete this;
	}
	return true;
}

bool World::Show()
{
	g_spirit1->Show(800.0f, 600.0f, 100.0f, 100.0f);

	return true;
}
