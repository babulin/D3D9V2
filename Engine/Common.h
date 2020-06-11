#pragma once
#include <Windows.h>
#include <iostream>

#define AHLIN_API __declspec(dllexport)
#define AGE_VERSION 0xd2
#define AGE_GRAPHIES 1 //1-DX 2-OpenGL

#if AGE_GRAPHIES == 1

	//Direct3D-9
	#include <d3dx9.h>
	#include <d3d9.h>
	#pragma comment(lib,"d3d9.lib")
	#pragma comment(lib,"d3dx9.lib")//d3d链接库

	//DirectInput8
	#define DIRECTINPUT_VERSION 0x0800 
	#include <dinput.h>
	#pragma comment(lib,"dinput8.lib")//使用DirectInput必须包含的头文件，注意这里有8
	#pragma comment(lib,"DXGuid.lib")

	//XAudio
	#include <XAudio2.h>
	#pragma comment(lib,"Ole32.lib")

	typedef IDirect3D9* AGE_API;
	typedef IDirect3DDevice9* AGE_DEVICE;

#elif AGE_GRAPHIES == 2

#endif

typedef bool (*frameCallback)();




