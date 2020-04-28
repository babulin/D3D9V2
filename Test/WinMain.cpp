#include <Windows.h>
#include <Engine.h>

using namespace AEngine;

Engine* g_engine;

void Render() {
	//MessageBox(NULL, L"Show！", L"小兔叽!", MB_OK);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//引擎点火
	g_engine = Engine_Start();

	//设置窗口大小
	g_engine->SetWndSize(800.0f, 600.0f);

	//设置回调函数
	g_engine->SetCallBack(Render);

	//启动引擎
	if (g_engine->Init(hInstance) != ExCode::EX_OK) {
		MessageBox(NULL, L"引擎启动失败！",L"小兔叽!",MB_OK);
	}

	//运转
	g_engine->Run();

	//结束

	return 0;
}