#pragma once
#include "Common.h"
#include "EngineConfig.h"

//�Զ���ͷ�ļ�
#include "zlibwapi.h"
#pragma comment(lib,"zlibwapi_x64.lib")

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

//��Ϣsize
#define MSG_SIZE 255

//wzxͷ���ṹ
struct WzxHeader {
	char description[20];	//www.shandagames.com
	int x1[6];				//ռλ
	int imageCount;			//ͼƬ����
};

//Wzlͷ���ṹ
struct WzlHeader {
	char description[44];	//www.shandagames.com
	int imageCount;			//ͼƬ����
	int x3[4];				//ռλ
};

//WzlͼƬ��Ϣ�ṹ
struct WzlBmpInfo {
	BYTE pixelFormat;	//ͼƬλ��
	BYTE compressed;	//��ʾͼƬ�����Ƿ񾭹�gzipѹ��
	BYTE reserve;		//ռλ
	BYTE compressLevel; //���ͼƬ������ѹ����������ͱ�ʾѹ���ĵȼ�
	short width;		//ͼƬ���
	short height;		//ͼƬ�߶�
	short x;			//ƫ��x
	short y;			//ƫ��y
	int size;			//ͼƬ���ݳ���[ѹ�����]
};

//����״̬
struct HumCode
{
	int STAND = 0;					//4֡ ��4֡[վ��]
	int WALK = STAND + 64;			//6֡ ��2֡[����]
	int RUN = WALK + 64;			//6֡ ��2֡[����]
	int ATTACK_POS = RUN + 64;		//8֡ ��0֡[׼��ս��]
	int ATTACK = ATTACK_POS + 8;	//6֡ ��2֡[���ֹ���]
	int ATTACK2 = ATTACK + 64;		//6֡ ��2֡[�ڿ�]
	int ATTACK3 = ATTACK2 + 64;		//8֡ ��0֡[�տ�]
	int SPELLS = ATTACK3 + 64;		//6֡ ��2֡[ʩ��]
	int DIG_MEAT = SPELLS + 64;		//2֡ ��0֡[����]
	int INJURED = DIG_MEAT + 16;	//3֡ ��5֡[����]
	int DEATH = INJURED + 64;		//4֡ ��4֡[����]
};

//UI���
struct UICode {
	//1024*768 ����
	int BG1 = 1813;
	int BG2 = 1814;
	int BG3 = 1815;
	//800*600 ����
	int BG4 = 1793;
	int BG5 = 1794;
	int BG6 = 1795;
};
