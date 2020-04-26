#pragma once
#include "Common.h"
#include "D3D9.h"

class D3DApp {
	GameWind* pGameWind;
	D3D9* g_d3d9;
public:
	D3DApp(GameWind* GameWind);
	~D3DApp();
	HRESULT Init();
	void Render();
	void Clear();
};