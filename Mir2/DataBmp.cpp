#include "DataBmp.h"
#include "Common.h"
#include "D3D9.h"

DataBmp::DataBmp()
{
	 GetD3DDevice(&m_d3dDevice);
}

DataBmp::~DataBmp()
{
	if (p_GPShader != nullptr)
	{
		delete p_GPShader;
	}
}

void DataBmp::CreateTexture1x1()
{
	//---------------------------------------------------------
	//����1X1
	if (FAILED(m_d3dDevice->CreateTexture(1, 1, 0, D3DUSAGE_DYNAMIC, D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, &m_Texture1x1, nullptr))) {
		MessageBox(NULL, L"����1x1����ʧ��", L"С��ߴ", MB_OK);
	}

	D3DSURFACE_DESC desc;
	m_Texture1x1->GetLevelDesc(0, &desc);

	D3DLOCKED_RECT lockRect;
	m_Texture1x1->LockRect(0, &lockRect, 0, 0);

	D3DXVECTOR4* Data = (D3DXVECTOR4*)lockRect.pBits;

	//��ֵ
	for (UINT h = 0; h < desc.Height; h++)
	{
		for (UINT w = 0; w < desc.Width; w++)
		{
			UINT index = h * lockRect.Pitch / 16 + w;
			//Data[index] = COLORF_BLACK;
			Data[index] = COLORF_WHITE;
		}
	}

	m_Texture1x1->UnlockRect(0);
}

void DataBmp::CreateTextureToFile(const TCHAR file[])
{
	//---------------------------------------------------------
	if (D3DXCreateTextureFromFile(m_d3dDevice, file, &m_Texture) != D3D_OK) {
		MessageBox(NULL, L"�������ʧ��", L"error", MB_OK);
	}
}

void DataBmp::CreateTexture()
{
	if (p_Data == nullptr){
		//���������Ϣ
		if (HAS_DEBUG)
		{
			char buf[MSG_SIZE] = { 0 };
			sprintf_s(buf, "[DataBmp] sort:%d ��������ʧ��!", sort);
			Log::Debug(buf);
		}
		return;
	}

	//����
	D3DSURFACE_DESC m_d3dSurfaceDesc = {};//����
	HRESULT hr = S_OK;

	///������ͼ
	D3DFORMAT fmt = m_BmpInfo.pixelFormat == 3 ? D3DFMT_A8R8G8B8 : D3DFMT_R5G6B5;
	hr = m_d3dDevice->CreateTexture(m_BmpInfo.width, m_BmpInfo.height, 0, D3DUSAGE_DYNAMIC, fmt, D3DPOOL_DEFAULT, &m_Texture, NULL);

	//��ȡ������Ϣ
	m_Texture->GetLevelDesc(0, &m_d3dSurfaceDesc);

	///��������
	D3DLOCKED_RECT lockRect;
	m_Texture->LockRect(0, &lockRect, 0, 0);

	int sort = 0;
	int index = 0;
	UINT height = m_d3dSurfaceDesc.Height;
	UINT width = m_d3dSurfaceDesc.Width;

	DWORD* imageData3 = nullptr;
	SHORT* imageData5 = nullptr;
	if (m_BmpInfo.pixelFormat == 3)
	{
		imageData3 = (DWORD*)lockRect.pBits;
	}
	else if (m_BmpInfo.pixelFormat == 5)
	{
		imageData5 = (SHORT*)lockRect.pBits;
	}

	//��ȡ��ɫ��
	//OpenRGB();

	for (UINT h = 0; h < height; h++)
	{
		for (UINT w = 0; w < width; w++)
		{
			if (m_BmpInfo.pixelFormat == 3) {
				//���� ��һ�� ��ͼƬ�����һ�� ���ݴ������¶�ȡ
				//D3DFMT_A8R8G8B8
				sort = (h * width) + w;
				BYTE  r = p_color[p_Data[sort]].peRed;
				BYTE  g = p_color[p_Data[sort]].peGreen;
				BYTE  b = p_color[p_Data[sort]].peBlue;
				//BYTE  r = aColors[data[sort]].rgbRed;
				//BYTE  g = aColors[data[sort]].rgbGreen;
				//BYTE  b = aColors[data[sort]].rgbBlue;
				DWORD color = D3DCOLOR_ARGB(0xff, r, g, b);
				//index = (height - h) * width + w;

				//ͼƬ���� ���ƴ�������
				UINT index = (height - 1 - h) * lockRect.Pitch / 4 + w;
				if (color != 0xff000000)
				{
					imageData3[index] = D3DCOLOR_ARGB(0xff, r, g, b);
				}
				else {
					imageData3[index] = D3DCOLOR_ARGB(0, 0, 0, 0);
				}
			}
			else if (m_BmpInfo.pixelFormat == 5)
			{
				//D3DFMT_R5G6B5
				sort = ((h * width) + w) * 2;
				BYTE sh1 = p_Data[sort];
				BYTE sh2 = p_Data[sort + 1];
				USHORT sVal = (sh2 << 8) | sh1;

				index = (height - 1 - h) * lockRect.Pitch / 2 + w;
				imageData5[index] = sVal;
			}
		}
	}

	//����
	m_Texture->UnlockRect(0);
	return;
	//-------------------------------------
	if (m_BmpInfo.pixelFormat == 5) {

		LPDIRECT3DTEXTURE9 dstTexture = NULL;

		//�½�һ��D3DFMT_A8R8G8B8
		IDirect3DSurface9* m_srcD3dSurface;
		IDirect3DSurface9* m_dstD3dSurface;

		hr = m_d3dDevice->CreateTexture(m_BmpInfo.width, m_BmpInfo.height, 0, D3DUSAGE_DYNAMIC, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &dstTexture, NULL);
		dstTexture->GetSurfaceLevel(0, &m_dstD3dSurface);
		m_Texture->GetSurfaceLevel(0, &m_srcD3dSurface);

		D3DXLoadSurfaceFromSurface(
			m_dstD3dSurface,
			NULL, NULL,
			m_srcD3dSurface,
			NULL, NULL,
			D3DX_FILTER_LINEAR,
			D3DCOLOR_ARGB(0, 0, 0, 0)
		);
		D3DSURFACE_DESC d3ddesc;
		m_dstD3dSurface->GetDesc(&d3ddesc);

		///��������
		D3DLOCKED_RECT lockr = { 0 };
		m_dstD3dSurface->LockRect(&lockr, 0, 0);
		DWORD* imageData33 = (DWORD*)lockr.pBits;

		//����
		//data16 = new BYTE[height * width];

		DWORD color = 0;
		for (UINT i = 0; i < d3ddesc.Height; i++)
		{
			for (UINT j = 0; j < d3ddesc.Width; j++)
			{
				UINT index = i * lockr.Pitch / 4 + j;
				if (imageData33[index] == 0xff000000)
				{
					imageData33[index] = D3DCOLOR_ARGB(1, 2, 3, 4);
				}
				else {

					//imageData33[index] = D3DCOLOR_ARGB(0, 0, 0, 0);
				}

				//int sort = i * d3ddesc.Width + j;
				//ColorARGB* tColor = (ColorARGB*)&imageData33[index];
				//PALETTEENTRY cl = { tColor->R,tColor->G,tColor->B};
				//data16[sort] = FindColor(cl);
			}
		}

		m_dstD3dSurface->UnlockRect();

		//�ͷ�֮ǰ��
		m_Texture->Release();
		m_Texture = dstTexture;
	}
}


void DataBmp::SetPSShader(GPShader* _psshader)
{
	p_GPShader = _psshader;
}

void DataBmp::Draw(float x, float y)
{
	m_d3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	//m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//ʹ��������ɫ��
	if (p_GPShader != nullptr)
	{
		p_GPShader->SetPixelShader();
	}
	else {
		m_d3dDevice->SetPixelShader(nullptr);
	}

	//0 1    //0 
	//  2    //3 2
	float wo = m_BmpInfo.width, ho = m_BmpInfo.height;
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

	//ʹ������
	m_d3dDevice->SetTexture(0, m_Texture);

	//���ƶ��㻺��
	m_d3dDevice->SetFVF(UV1Vertex::FVF);
	m_d3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, vertex, sizeof(UV1Vertex));
}

void DataBmp::Draw(float wo, float ho,float x, float y)
{
	m_d3dDevice->SetRenderState(D3DRS_LIGHTING, false);
	//m_d3dDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

	//ʹ��������ɫ��
	if (p_GPShader != nullptr)
	{
		p_GPShader->SetPixelShader();
	}
	else {
		m_d3dDevice->SetPixelShader(nullptr);
	}

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

	//ʹ������
	m_d3dDevice->SetTexture(0, m_Texture);

	//���ƶ��㻺��
	m_d3dDevice->SetFVF(UV1Vertex::FVF);
	m_d3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, vertex, sizeof(UV1Vertex));
}