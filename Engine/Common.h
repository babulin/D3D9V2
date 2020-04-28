#pragma once
#include <Windows.h>
#include "GError.h"

#define AHLIN_API __declspec(dllexport)

#include <d3dx9.h>
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")//d3d¡¥Ω”ø‚

typedef void (*CALLFUNC)()