#include <Windows.h>
#include <Engine.h>

using namespace AEngine;

Engine* g_engine;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//��������
	g_engine = Engine_Start();

	//���ô��ڴ�С
	g_engine->SetWndSize(800.0f, 600.0f);

	g_engine->Init();
	return 0;
}