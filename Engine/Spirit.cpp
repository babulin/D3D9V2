#include "Spirit.h"
namespace AEngine {

	Spirit::Spirit(const wchar_t _file[], const wchar_t _file_2[])
	{
		//��������
		lstrcpy(file, _file);
		lstrcpy(file_2, _file_2);
	}

	Spirit::~Spirit()
	{
		pTexture1->Release();
	}

	void Spirit::Load() {

		//����ͼƬ
		HRESULT hr = D3DXCreateTextureFromFile(GetDevice(), file, &pTexture1);
		if (FAILED(hr))
		{
			MessageBox(nullptr, L"��������ʧ��", L"��Ϣ��ʾ",MB_OK);
		}

		//����ͼƬ
		hr = D3DXCreateTextureFromFile(GetDevice(), file_2, &pTexture2);
		if (FAILED(hr))
		{
			MessageBox(nullptr, L"��������ʧ��", L"��Ϣ��ʾ", MB_OK);
		}
	}

	void Spirit::Show(float wo, float ho, float x, float y)
	{
		//�豸���
		LPDIRECT3DDEVICE9 device = GetDevice();

		device->SetRenderState(D3DRS_LIGHTING, false);
		//m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		//ʹ��������ɫ��

		//0 1    //0 
		//  2    //3 2
		//float wo = m_BmpInfo.width, ho = m_BmpInfo.height;
		float min = 0.0f, max = 1.0f;
		x = x - 0.05f;
		y = y - 0.05f;

		float x1 = x - 0.05f + wo;
		float y1 = y - 0.05f;

		UV1Vertex vertex[] = {
			{ x		 , y		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x + wo , y		, 1.0f	, 1.0f, COLOR_WHITE	,max,min},
			{ x + wo , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x		 , y		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x + wo , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x		 , y + ho	, 1.0f	, 1.0f, COLOR_WHITE	,min,max},

			{ x1	  , y1		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x1 + wo , y1		, 1.0f	, 1.0f, COLOR_WHITE	,max,min},
			{ x1 + wo , y1 + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x1	  , y1		, 1.0f	, 1.0f, COLOR_WHITE	,min,min},
			{ x1 + wo , y1 + ho	, 1.0f	, 1.0f, COLOR_WHITE	,max,max},
			{ x1	  , y1 + ho	, 1.0f	, 1.0f, COLOR_WHITE	,min,max},
		};

		//ʹ������
		device->SetTexture(0, pTexture1);
		device->SetTexture(1, pTexture2);

		//���ƶ��㻺��
		device->SetFVF(UV1Vertex::FVF);
		device->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 4, vertex, sizeof(UV1Vertex));
	}
}
