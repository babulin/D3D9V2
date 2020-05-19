#pragma once
#include <Windows.h>
#include <iostream>

#define AHLIN_API __declspec(dllexport)

#define AGE_GRAPHIES 1 //1-DX 2-OpenGL

#if AGE_GRAPHIES == 1
	#include <d3dx9.h>
	#include <d3d9.h>
	#pragma comment(lib,"d3d9.lib")
	#pragma comment(lib,"d3dx9.lib")//d3d¡¥Ω”ø‚
	typedef IDirect3D9* AGE_API;
	typedef IDirect3DDevice9* AGE_DEVICE;

#elif AGE_GRAPHIES == 2

#endif

typedef bool (*frameCallback)();

#define AGE_VERSION 0xd2


