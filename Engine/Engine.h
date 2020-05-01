#pragma once
#include "Common.h"
#include "IGameWnd.h"	//窗口
#include "Graphies.h"	//绘图

using namespace AhlinI;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;		//游戏窗口
		Graphies* pGraphies;	//绘图对象
		frameCallback framFunc;	//回调函数
	public:
		Engine();
		ExCode Init();	//初始化
		void Run();		//渲染
		void Close();	//关闭
		void SetCallBack(frameCallback callback) { framFunc = callback; };

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

		//画家
		void SetSpirit();
	};

	//引擎启动
	AHLIN_API Engine* Engine_Start(const int ver);
}
