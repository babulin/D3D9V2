#include <Windows.h>
#include <Engine.h>

using namespace AEngine;

Engine* g_engine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//启动引擎
	g_engine = Engine_Start();

	//设置窗口大小
	g_engine->SetWndSize(800.0f, 600.0f);

	g_engine->Init();
	return 0;
}