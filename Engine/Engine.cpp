#include "Engine.h"
#include "D3D9.h"

namespace AEngine {

	//初始化静态成员
	Engine* Engine::pEngine = nullptr;

	//创建引擎
	 Engine* Engine::CreateEngine(const int ver)
	{
		if (ver != AGE_VERSION)
		{
			return nullptr;
		}

		if (pEngine == nullptr)
		{
			pEngine = new Engine();
		}
		return pEngine;
	}

	//---------------------------------------
	//| 构造函数
	//---------------------------------------
	Engine::Engine()
	{
		pGameWnd = GameWnd::CreateWnd();
		pD3D9 = D3D9::GetInstance();
		pD3D9->SetWnd(pGameWnd);
	}


	//---------------------------------------
	//| 初始化
	//---------------------------------------
	bool Engine::Init()
	{
		//初始化窗口
		if ( ! pGameWnd->Create()) 
		{
			return false;
		}

		//初始化DX9
		if ( ! pD3D9->Init())
		{
			return false;
		}

		//初始化游戏资源
		if (pGame == nullptr)
		{
			MessageBox(nullptr, L"Engine::SetGame();必须设置一个游戏类!",L"error",MB_OK);
			return false;
		}

		if ( ! pGame->Init()) {
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
				break;
			}

			//绘制
			pD3D9->BeginScene();

			//回调
			if (!pGame->Show()){
				break;
			}

			pD3D9->EndScene();
		}
	}

	//---------------------------------------
	//| 引擎关闭
	//---------------------------------------
	void Engine::Close()
	{
		if (pGameWnd != nullptr)
		{
			delete pGameWnd;
			pGameWnd = nullptr;
		}

		if (pD3D9 != nullptr)
		{
			delete pD3D9;
			pD3D9 = nullptr;
		}

		delete this;
	}

	//---------------------------------------
	//| 游戏更新类
	//---------------------------------------
	void Engine::SetGame(IGame* _game)
	{
		pGame = _game;
	}

	//设置标题
	void Engine::SetTitle(wstring _title)
	{
		if (pGameWnd != nullptr)
			pGameWnd->SetTitle(_title);
	}

	//设置大小
	void Engine::SetSize(int w, int h)
	{
		if (pGameWnd != nullptr)
			pGameWnd->SetSize(w, h);
	}
}