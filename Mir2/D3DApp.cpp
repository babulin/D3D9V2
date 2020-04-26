#include "D3DApp.h"
#include "GTime.h"
#include "GameScene.h"

static int GProgress = GP_STARTUP;	//��Ϸ����
GameScene g_GameScene;				//��Ϸ��������

D3DApp::D3DApp(GameWind* GameWind)
{
	Log::Debug("D3DApp()����\n");
	pGameWind = GameWind;
	g_d3d9 = nullptr;
}

D3DApp::~D3DApp()
{
	Log::Debug("~D3DApp()����\n");
}

HRESULT D3DApp::Init()
{
	//����D3D
	g_d3d9 = new D3D9(pGameWind);

	//��ʼ��
	if (FAILED(g_d3d9->InitD3D())) {
		MessageBox(pGameWind->mHwnd, TEXT("InitD3D��ʼ��ʧ��"), TEXT("������ʾ"), MB_OK);
		return E_FAIL;
	}

	//��Ϸ������ʼ��
	g_GameScene.Init();

	return S_OK;
}


//��ʱ
bool hasBtn = false;
void D3DApp::Render()
{
	GTime::run();//��ʼ��ʱ
	//----------------------------------------
	g_d3d9->BeginScene();
	//----------------------------------------

	//ģ���л�����
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

	//GTime::GetCountDown();//֡����ʱ��
	GTime::over();//������ʱ
}

void D3DApp::Clear()
{
	Log::Debug("D3DApp::Clear()����\n");
	//ɾ������
	if (g_d3d9 != nullptr)
		delete g_d3d9;
}
