#pragma once
#include "Common.h"
#include  "IGraphies.h"

class D3D9 :public IGraphies{
private:
	LPDIRECT3D9 m_d3d9;				//d3d����
	LPD3DXFONT m_d3dFont;			//���ֶ���
public:
	GameWind* pGameWind;			//���ڶ���
public:
	D3D9(GameWind* GameWind);
	~D3D9();
	HRESULT InitD3D();
	void BeginScene();
	void EndScene();
};