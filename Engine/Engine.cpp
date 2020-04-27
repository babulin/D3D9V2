#include "Engine.h"
#include "GameWnd.h"

using namespace AEngine;
using namespace AhlinI;

Engine* gEngine = nullptr;

//��������
Engine* AEngine::Engine_Start()
{
	if (gEngine == nullptr)
	{
		gEngine = new Engine();
	}
	return gEngine;
}

Engine::Engine()
{
	//����
	pGameWnd = new GameWnd();
}


ExCode Engine::Init()
{
	pGameWnd->CreateWnd();
	return ExCode::EX_OK;
}

void Engine::Run()
{

}

void Engine::Close()
{

}

void AEngine::Engine::SetWndSize(float width, float height)
{
	pGameWnd->SetSize(width, height);
}