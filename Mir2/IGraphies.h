#pragma once
#include "Common.h"

class IGraphies {

public:
	IGraphies() {};
	virtual ~IGraphies() {};
	virtual HRESULT InitD3D() = 0;
	virtual void BeginScene() = 0;
	virtual void EndScene() = 0;
};

//获取D3D设备
void GetD3DDevice(LPDIRECT3DDEVICE9* D3DDevice);