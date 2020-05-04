#include "Spirit.h"
namespace AEngine {

	Spirit::Spirit(const wchar_t _file[])
	{
		//复制名称
		lstrcpy(file, _file);
	}

	Spirit::~Spirit()
	{
		pTexture1->Release();
	}

	void Spirit::Load() {

		//加载图片
		HRESULT hr = D3DXCreateTextureFromFile(GetDevice(), file, &pTexture1);
		if (FAILED(hr))
		{
			MessageBox(nullptr, L"创建纹理失败", L"消息提示",MB_OK);
		}
	}

	void Spirit::Show(float wo, float ho, float x, float y)
	{
		//设备句柄
		LPDIRECT3DDEVICE9 device = GetDevice();

		device->SetRenderState(D3DRS_LIGHTING, false);
		//m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		//使用像素着色器

		//0 1    //0 
		//  2    //3 2
		//float wo = m_BmpInfo.width, ho = m_BmpInfo.height;
		float min = 0.0f, max = 1.0f;
		x = x - 0.05f;
		y = y - 0.05f;
		UV1Vertex vertex[] = {
			{ x		 , y		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x + wo , y		, 1.0f	, 1.0f, COLOR_WHITE	,max,min},
			{ x + wo , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x		 , y		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x + wo , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x		 , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,min,max},
		};

		//使用纹理
		device->SetTexture(0, pTexture1);

		//绘制顶点缓存
		device->SetFVF(UV1Vertex::FVF);
		device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, vertex, sizeof(UV1Vertex));
	}
}
