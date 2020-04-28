#include "D3D9.h"

ExCode AEngine::D3D9::Init()
{
	//创建D3D对象
	m_d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	if (m_d3d9 == NULL) {
		return EX_FAIL;
	}

	///获取显卡模式
	D3DDISPLAYMODE d3ddm;
	if (FAILED(m_d3d9->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &d3ddm)))
	{
		return EX_FAIL;
	}

	//校验硬件顶点运算
	D3DCAPS9 caps;
	m_d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	int vp = 0;
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
	{
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	}
	else {
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
	}

	//检测shader版本
	if (caps.VertexShaderVersion < D3DVS_VERSION(3, 0)) {
		MessageBox(pGameWnd->hwnd, L"不支持3.0顶点着色器", L"提示", NULL);
	}

	if (caps.PixelShaderVersion < D3DPS_VERSION(3, 0)) {
		MessageBox(pGameWnd->hwnd, L"不支持3.0像素着色器", L"提示", NULL);
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;//自动维护深度缓存
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;//深度缓存像素格式[clear时清除ZBUFFER] D3DCLEAR_ZBUFFER

	//创建device设备
	if (FAILED(m_d3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, pGameWnd->hwnd, vp, &d3dpp, &m_d3dDevice))) {
		return EX_FAIL;
	}

	return EX_OK;
}

void AEngine::D3D9::SetSpirit()
{

}

void AEngine::D3D9::Draw()
{
	m_d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(50, 50, 50), 1.0f, 0);
	m_d3dDevice->BeginScene();
	//--------------------------------------------------



	//--------------------------------------------------
	m_d3dDevice->EndScene();
	m_d3dDevice->Present(NULL, NULL, NULL, NULL);
}
