#include "Game.h"
#include "World.h"
#include "Spirit.h"
#include "Engine.h"
#include <Windows.h>

Spirit* g_spirit;
bool Game::Init()
{
	std::cout << "[" << this << "]" << "Game::Init()" << std::endl;

	//��ʼ��һЩ��Դ
	g_spirit = new Spirit(L"1.png");
	g_spirit->Load();

	return true;
}

bool Game::Update()
{
	//��������

	//�л�����
	if (GetAsyncKeyState('1'))
	{
		delete g_spirit;
		g_spirit = nullptr;

		//�л���World
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
	//��ʾ

	if (g_spirit != nullptr)
	{
		g_spirit->Show(1024.0f,768.0f,0.0f,0.0f);
	}

	return true;
}