#pragma once
#include "Common.h"
#include "GameWnd.h"	//窗口
#include "D3D9.h"		//渲染器
#include "DXInput.h"	//输入控制器
#include "DXSound.h"	//音频输入
//#include "IGame.h"	//游戏
#include "SceneManage.h"//场景管理

namespace AEngine {

	class AHLIN_API Engine {
	private:
		GameWnd* pGameWnd;		//游戏窗口
		D3D9* pD3D9;			//渲染器
		DXInput* pDInput;		//输入控制
		DXSound* pDSound;		//音频输入
		SceneManage* pScene;	//场景管理

		static Engine* pEngine;	//引擎对象单例
	private:
		Engine();
	public:
		//static
		static Engine* CreateEngine(const int ver);	//创建引擎

		//engine
		bool Init();					//初始化
		void Run();						//运行
		void Close();					//关闭

		//get
		void SetGame(SceneManage* _scene);		//设置场景管理

		//windows
		void SetTitle(wstring _title);
		void SetSize(int w, int h);
	};
}
