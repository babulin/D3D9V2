#pragma once
#include <Windows.h> //OutputDebugString
#include <string>	//FILE

#include <d3dx9.h>
#include <d3d9.h>
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")//d3d链接库
#pragma comment(lib,"winmm.lib") //timeGetTime()

//自定义头文件
#include "Include/GameWind.h"
#include "Include/zlibwapi.h"
#ifdef X86
#pragma comment(lib,"GameWind_x86.lib")
#pragma comment(lib,"zlibwapi_x86.lib")
#else
#pragma comment(lib,"GameWind_x64.lib")
#pragma comment(lib,"zlibwapi_x64.lib")
#endif // ZLIB_WINAPI

#define HAS_DEBUG true
#define MSG_SIZE 255
#include "Log.h"

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

//游戏进度
enum GAME_PROGRESS
{
	GP_STARTUP = 0,		//启动界面
	GP_SIGNIN = 1,		//登陆界面
	GP_ROLESELECT = 2,	//选择角色
	GP_WORLD = 3		//进入游戏
};

//wzx头部结构
struct WzxHeader {
	char description[20];	//www.shandagames.com
	int x1[6];				//占位
	int imageCount;			//图片数量
};

//Wzl头部结构
struct WzlHeader {
	char description[44];	//www.shandagames.com
	int imageCount;			//图片数量
	int x3[4];				//占位
};

//Wzl图片信息结构
struct WzlBmpInfo {
	BYTE pixelFormat;	//图片位深
	BYTE compressed;	//表示图片数据是否经过gzip压缩
	BYTE reserve;		//占位
	BYTE compressLevel; //如果图片数据是压缩过，这个就表示压缩的等级
	short width;		//图片宽度
	short height;		//图片高度
	short x;			//偏移x
	short y;			//偏移y
	int size;			//图片数据长度[压缩后的]
};

//人物状态
struct HumCode
{
	int STAND = 0;					//4帧 空4帧[站立]
	int WALK = STAND + 64;			//6帧 空2帧[行走]
	int RUN = WALK + 64;			//6帧 空2帧[奔跑]
	int ATTACK_POS = RUN + 64;		//8帧 空0帧[准备战斗]
	int ATTACK = ATTACK_POS + 8;	//6帧 空2帧[单手攻击]
	int ATTACK2 = ATTACK + 64;		//6帧 空2帧[挖矿]
	int ATTACK3 = ATTACK2 + 64;		//8帧 空0帧[空砍]
	int SPELLS = ATTACK3 + 64;		//6帧 空2帧[施法]
	int DIG_MEAT = SPELLS + 64;		//2帧 空0帧[挖肉]
	int INJURED = DIG_MEAT + 16;	//3帧 空5帧[受伤]
	int DEATH = INJURED + 64;		//4帧 空4帧[死亡]
};

//UI序号
struct UICode {
	int BG1 = 1815;		//1024*768 背景
	int BG2 = 1793;		//800*600 背景
	int BG3 = 1815;		//1024*768 背景
};

//顶点格式数组
struct UV1Vertex
{
	float x, y, z,rhw;
	DWORD color;
	float u, v;
	static const DWORD FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
};