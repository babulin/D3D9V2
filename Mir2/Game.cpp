#include "Common.h"
#include "D3DApp.h"
#include "Samples.h"

void Create(Person** person) {
	*person = new Person();
}

GameWind* g_wnd;
D3DApp* g_d3dApp;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
#if 0
	//智能指针类
	ComPtr<Person*> gPerson;
	//初始化
	Create(gPerson.GetAddress());
	//使用
	gPerson.Get()->Show();

	return 0;
#endif // 0

	//创建窗口
	g_wnd = windCreate(hInstance, 1024, 768, L"D3D9 PixelShader 2.0");

	//创建应用程序
	g_d3dApp = new D3DApp(g_wnd);
	if (FAILED(g_d3dApp->Init())) {
		MessageBox(g_wnd->mHwnd, TEXT("D3DApp初始化失败"), TEXT("错误提示"), MB_OK);
		return 0;
	}

	//游戏循环
	while (g_wnd->ProcessMessage()) {
		g_d3dApp->Render();
	}

	g_d3dApp->Clear();

	if (g_d3dApp != nullptr)
	{
		delete g_d3dApp;
	}

	safeDelete();

	return 0;
}