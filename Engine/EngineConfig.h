#pragma once
#include "Common.h"

//D3DFMT_A8R8G8B8	ARGB
#define COLOR_RED D3DCOLOR_ARGB(255, 255, 0, 0)
#define COLOR_GREEN D3DCOLOR_ARGB(255, 0, 255, 0)
#define COLOR_BLUE D3DCOLOR_ARGB(255, 0, 0, 255)
#define COLOR_WHITE D3DCOLOR_ARGB(255, 255, 255, 255)

//顶点格式数组
struct UV1Vertex
{
	float x, y, z, rhw;
	DWORD color;
	float u, v;
	static const DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
};

struct UV2Vertex
{
	float x, y, z, rhw;
	DWORD color;
	float u1, v1;
	float u2, v2;
	static const DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX2;
};
