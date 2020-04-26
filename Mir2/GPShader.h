#pragma once
#include "Common.h"

class GPShader {
protected:
	TCHAR file[64] = {0};
	LPDIRECT3DDEVICE9 m_d3dDevice;
	D3DXVECTOR4 mDstColor = COLORF_BLACK;
	D3DXVECTOR4 mSrcColor = COLORF_BLACK;
	float speed = 0.0f;
public:
	LPD3DXCONSTANTTABLE mConstTable = nullptr;			//常量表接口
	LPDIRECT3DPIXELSHADER9 mPixelShader = nullptr;		//像素着色器接口
public:
	GPShader(const TCHAR _file[]);
	~GPShader();
	void Load();
	void SetColorToColor(D3DXVECTOR4 _DstColor, D3DXVECTOR4 _SrcColor, float _speed = 0.01f);
	void SetPixelShader();
	bool hasMask();
private:
	float addFloat(float df, float sf);
};