#include "Engine.h"
#include "D3D9.h"

namespace AEngine {

	Engine* gEngine = nullptr;

	//启动引擎
	Engine* AEngine::CreateEngine(const int ver)
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

	//---------------------------------------
	//| 构造函数
	//---------------------------------------
	Engine::Engine()
	{
		pGameWnd = AEngine::CreateWnd();
	}

	//---------------------------------------
	//| 初始化
	//---------------------------------------
	bool Engine::Init()
	{
		//初始化窗口
		HINSTANCE hInst = GetModuleHandle(nullptr);
		pGameWnd->Init(hInst);

		//初始化渲染模块
		pD3D9 = D3D9::GetInstance();
		pD3D9->SetWnd(pGameWnd);
		if ( !pD3D9->Init())
		{
			return false;
		}

		//初始化游戏资源
		if (!pGame->Init()) {
			return false;
		}

		//初始化输入

		return true;
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
			if ( !pGame->Update())
			{
				//结束
				break;
			}

			//绘制
			pD3D9->BeginScene();

			//回调
			if (!pGame->Show())
			{
				//结束
				break;
			}

			pD3D9->EndScene();
		}
	}

	void Engine::Close()
	{
		if (pGameWnd != nullptr)
		{
			delete pGameWnd;
			pGameWnd = nullptr;
		}

		if (pD3D9 != nullptr)
		{
			pD3D9->Release();
		}

		delete this;
	}
}