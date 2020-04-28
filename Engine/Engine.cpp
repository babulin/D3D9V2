#include "Engine.h"
#include "GameWnd.h"

using namespace AEngine;
using namespace AhlinI;

Engine* gEngine = nullptr;

//启动引擎
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
	//窗口
	pGameWnd = AhlinI::CreateWnd();
}


ExCode Engine::Init(HINSTANCE hInst)
{
	//初始化窗口
	pGameWnd->Init(hInst);

	//初始化渲染模块

	return ExCode::EX_OK;
}

bool Engine::Run()
{
	//循环
	while (pGameWnd->GetMsg())
	{
		//回调
		render();
	}
	return false;
}

void Engine::Close()
{
	if (pGameWnd != nullptr)
	{
		delete pGameWnd;
		pGameWnd = nullptr;
	}
}