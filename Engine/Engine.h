#pragma once
#include "Common.h"
#include "IGameWnd.h"

using namespace AhlinI;
//using AhlinI::ExCode;
//using AhlinI::IGameWnd;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;	//游戏窗口
		CALLFUNC render;
	public:
		Engine();
		ExCode Init(HINSTANCE hInst);	//初始化
		bool Run();		//渲染
		void Close();	//关闭
		void SetCallBack(CALLFUNC callback) { render = callback; };
		//窗口配置
		void SetWndSize(float width, float height) { pGameWnd->SetSize(width, height); }	//设置窗口大小
		void SetTitle(wstring title) { pGameWnd->SetTitle(title); }	//设置标题
	};

	//引擎启动
	AHLIN_API Engine* Engine_Start();
}
