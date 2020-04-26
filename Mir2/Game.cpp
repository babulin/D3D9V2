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
	//����ָ����
	ComPtr<Person*> gPerson;
	//��ʼ��
	Create(gPerson.GetAddress());
	//ʹ��
	gPerson.Get()->Show();

	return 0;
#endif // 0

	//��������
	g_wnd = windCreate(hInstance, 1024, 768, L"D3D9 PixelShader 2.0");

	//����Ӧ�ó���
	g_d3dApp = new D3DApp(g_wnd);
	if (FAILED(g_d3dApp->Init())) {
		MessageBox(g_wnd->mHwnd, TEXT("D3DApp��ʼ��ʧ��"), TEXT("������ʾ"), MB_OK);
		return 0;
	}

	//��Ϸѭ��
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