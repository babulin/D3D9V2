#include "D3DApp.h"
#include "GTime.h"
#include "GameScene.h"

static int GProgress = GP_STARTUP;	//游戏进度
GameScene g_GameScene;				//游戏场景管理

D3DApp::D3DApp(GameWind* GameWind)
{
	Log::Debug("D3DApp()构造\n");
	pGameWind = GameWind;
	g_d3d9 = nullptr;
}

D3DApp::~D3DApp()
{
	Log::Debug("~D3DApp()析构\n");
}

HRESULT D3DApp::Init()
{
	//创建D3D
	g_d3d9 = new D3D9(pGameWind);

	//初始化
	if (FAILED(g_d3d9->InitD3D())) {
		MessageBox(pGameWind->mHwnd, TEXT("InitD3D初始化失败"), TEXT("错误提示"), MB_OK);
		return E_FAIL;
	}

	//游戏场景初始化
	g_GameScene.Init();

	return S_OK;
}


//临时
bool hasBtn = false;
void D3DApp::Render()
{
	GTime::run();//开始计时
	//----------------------------------------
	g_d3d9->BeginScene();
	//----------------------------------------

	//模拟切换场景
	if (GetAsyncKeyState('1')) {
		if ( ! hasBtn)
		{
			GProgress++;
			if (GProgress > 3)
			{
				GProgress = 0;
			}
			hasBtn = true;
		}
	}
	else {
		hasBtn = false;
	}

	switch (GProgress)
	{
		case GP_STARTUP:
			g_GameScene.StartUp();
			break;
		case GP_SIGNIN:
			g_GameScene.SignIn();
			break;
		default:
			break;
	}

	//----------------------------------------
	g_d3d9->EndScene();
	//----------------------------------------

	//GTime::GetCountDown();//帧生成时间
	GTime::over();//结束计时
}

void D3DApp::Clear()
{
	Log::Debug("D3DApp::Clear()析构\n");
	//删除对象
	if (g_d3d9 != nullptr)
		delete g_d3d9;
}
