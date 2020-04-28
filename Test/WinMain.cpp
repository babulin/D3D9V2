#include <Windows.h>
#include <Engine.h>

using namespace AEngine;
#define HGE_DIRECTX_VER
Engine* g_engine = nullptr;

bool FrameFunc() {
	//MessageBox(NULL, L"Show��", L"С��ߴ!", MB_OK);

	//����һ��ͼƬ
	g_engine->SetSpirit();

	//����true [false �����]
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	//������
	g_engine = Engine_Start(AGE_VERSION);

	//���ñ���
	g_engine->SetTitle(L"Ahlin'sGE D3D9 V2.1.0");
	//���ô��ڴ�С
	g_engine->SetWndSize(1024.0f, 768.0f);
	//���ûص�����
	g_engine->SetCallBack(FrameFunc);

	//��������
	if (g_engine->Init() != ExCode::EX_OK) {
		MessageBox(NULL, L"��������ʧ�ܣ�",L"С��ߴ!",MB_OK);
	}

	//��ת
	g_engine->Run();

	//����
	g_engine->Close();

	return 0;
}