#pragma once
#include "Common.h"
#include  "IGraphies.h"

class D3D9 :public IGraphies{
private:
	LPDIRECT3D9 m_d3d9;				//d3d对象
	LPD3DXFONT m_d3dFont;			//文字对象
public:
	GameWind* pGameWind;			//窗口对象
public:
	D3D9(GameWind* GameWind);
	~D3D9();
	HRESULT InitD3D();
	void BeginScene();
	void EndScene();
};