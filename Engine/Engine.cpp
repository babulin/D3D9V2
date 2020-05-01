#include "Engine.h"
#include "GameWnd.h"
#include "D3D9.h"
#include "OpenGL.h"

using namespace AEngine;
using namespace AhlinI;

Engine* gEngine = nullptr;

//启动引擎
Engine* AEngine::Engine_Start(const int ver)
{
	if (ver != AGE_VERSION)
	{
		return nullptr;
	}

	if (gEngine == nullptr)
	{
		gEngine = new Engine();
	}
	return gEngine;
}

Engine::Engine()
{
	pGameWnd = AhlinI::CreateWnd();
}

//---------------------------------------
//|初始化
//---------------------------------------
ExCode Engine::Init()
{
	//初始化窗口
	HINSTANCE hInst = GetModuleHandle(nullptr);
	pGameWnd->Init(hInst);

	//初始化渲染模块
	pGraphies = new Graphies();
	pGraphies->Get().SetWnd(pGameWnd);
	if ( ! pGraphies->Init())
	{
		return EX_FAIL;
	}

	//初始化输入

	return EX_OK;
}

//---------------------------------------
//| 运行
//---------------------------------------
void Engine::Run()
{
	//循环
	while (pGameWnd->GetMsg())
	{
		//回调
		if ( ! framFunc())
		{
			//结束
			break;
		}

		//绘制
		pGraphies->Draw();
	}
}

void Engine::Close()
{
	if (pGameWnd != nullptr)
	{
		delete pGameWnd;
		pGameWnd = nullptr;
	}

	if (pGraphies != nullptr)
	{
		delete pGraphies;
		pGraphies = nullptr;
	}

	delete this;
}

void AEngine::Engine::SetSpirit()
{
	pGraphies->Get().SetSpirit();
}
