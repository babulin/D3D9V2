#pragma once
#include "Common.h"
#include "IGameWnd.h"	//窗口
#include "D3D9.h"		//渲染器
#include "IGame.h"		//游戏

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;		//游戏窗口
		D3D9* pD3D9;			//渲染器
		IGame* pGame;			//回调类
	public:
		//构造
		Engine();
		//初始化
		bool Init();
		//运行
		void Run();	
		//关闭
		void Close();	

		//设置回调类
		void SetCallBack(IGame* _game) { 
			pGame = _game; 
		};

		//设置窗口大小
		void SetWndSize(float width, float height) 
		{ 
			pGameWnd->SetSize(width, height); 
		}	

		//设置标题
		void SetTitle(wstring title) 
		{ 
			pGameWnd->SetTitle(title); 
		}	
	};

	//引擎启动
	AHLIN_API Engine* CreateEngine(const int ver);
}
