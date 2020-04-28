#include <Windows.h>
#include <Engine.h>

using namespace AEngine;

Engine* g_engine;

void Show() {

}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//������
	g_engine = Engine_Start();

	//���ô��ڴ�С
	g_engine->SetWndSize(800.0f, 600.0f);

	//���ûص�����
	g_engine->SetCallBack(Show);

	//��������
	if (g_engine->Init(hInstance) != ExCode::EX_OK) {
		MessageBox(NULL, L"��������ʧ�ܣ�",L"С��ߴ!",MB_OK);
	}

	//��ת
	g_engine->Run();

	//����

	return 0;
}