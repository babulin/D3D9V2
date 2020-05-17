#pragma once
#include <Windows.h>
#include <iostream>

#define AHLIN_API __declspec(dllexport)

#define AGE_GRAPHIES 1 //1-DX 2-OpenGL

#if AGE_GRAPHIES == 1
	#include <d3dx9.h>
	#include <d3d9.h>
	#pragma comment(lib,"d3d9.lib")
	#pragma comment(lib,"d3dx9.lib")//d3d链接库

	typedef IDirect3D9* AGE_API;
	typedef IDirect3DDevice9* AGE_DEVICE;

#elif AGE_GRAPHIES == 2

#endif

typedef bool (*frameCallback)();

#define AGE_VERSION 0xd2

//D3DFMT_A8R8G8B8	ARGB
#define COLOR_RED D3DCOLOR_ARGB(255, 255, 0, 0)
#define COLOR_GREEN D3DCOLOR_ARGB(255, 0, 255, 0)
#define COLOR_BLUE D3DCOLOR_ARGB(255, 0, 0, 255)
#define COLOR_WHITE D3DCOLOR_ARGB(255, 255, 255, 255)

//D3DFMT_A32B32G32R32F   RGBA
#define COLORF_RED D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f)
#define COLORF_GREEN D3DXVECTOR4(0.0f, 1.0f, 0.0f, 1.0f)
#define COLORF_BLUE D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f)
#define COLORF_WHITE D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f)
#define COLORF_HDR D3DXVECTOR4(2.0f, 2.0f, 2.0f, 2.0f)
#define COLORF_GREY D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f)
#define COLORF_BLACK D3DXVECTOR4(0.0f, 0.0f, 0.0f, 1.0f)
#define COLORF_LOW D3DXVECTOR4(-1.0f, -1.0f, -1.0f, 1.0f)

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

