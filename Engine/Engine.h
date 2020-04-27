#pragma once
#include "Common.h"
#include "IGameWnd.h"

using AhlinI::ExCode;
using AhlinI::IGameWnd;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;	//游戏窗口
	public:
		Engine();
		ExCode Init();	//初始化
		void Run();		//渲染
		void Close();	//关闭

		void SetWndSize(float width,float height);	//设置窗口大小
	};

	//引擎启动
	AHLIN_API Engine* Engine_Start();
}
