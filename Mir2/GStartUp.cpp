#include "GStartUp.h"
#include "Log.h"

GStartUp::GStartUp()
{
	Log::Debug("GStartUp()����\n");
}

GStartUp::~GStartUp()
{
	Log::Debug("~GStartUp()����\n");
}

void GStartUp::Init()
{
	if (hasInit)
	{
		return;
	}

	hasInit = true;

	//����Դ
	DataWzl g_wzlUI("Data\\ui");
	DataWzl g_wzlHUM("Data\\hum");

	//��ʼ��ͼƬ
	g_BG1Bmp = new DataBmp();
	g_BG2Bmp = new DataBmp();
	g_Logo = new DataBmp();

	//����Ч��
	g_LogoPs = new GPShader(TEXT("PS_01.hlsl"));
	g_LogoPs->SetColorToColor(COLORF_BLACK, COLORF_WHITE, 0.01f);

	//LOGO
	g_Logo->CreateTextureToFile(L"data\\logo.bmp");
	g_Logo->SetPSShader(g_LogoPs);


	//����Ч��
	g_PSShader = new GPShader(TEXT("PS_01.hlsl"));
	g_PSShader->SetColorToColor(COLORF_WHITE, COLORF_BLACK, 0.01f);

	//��ʼ��ͼƬ
	g_wzlUI.Load(g_uiCode.BG1, g_BG1Bmp);
	g_BG1Bmp->CreateTexture();
	g_BG1Bmp->SetPSShader(g_PSShader);

	//���صڶ��ű���
	g_wzlUI.Load(g_uiCode.BG2, g_BG2Bmp);
	g_BG2Bmp->CreateTexture();
	g_BG2Bmp->SetPSShader(g_PSShader);
}

void GStartUp::Show()
{
	static bool hasBtn = false;
	//ģ���л�����
	if (GetAsyncKeyState('2')) {
		if (!hasBtn)
		{
			//����Ч��
			g_LogoPs->SetColorToColor(COLORF_BLACK, COLORF_WHITE, 0.02f);
			g_PSShader->SetColorToColor(COLORF_WHITE, COLORF_BLACK, 0.02f);
			hasBtn = true;
		}
	}
	else {
		hasBtn = false;
	}

	if (!g_LogoPs->hasMask())
	{
		g_Logo->Draw(1024.0f, 768.0f, 0.0f, 0.0f);
	}
	else {
		g_BG1Bmp->Draw();
		g_BG2Bmp->Draw();
	}
}
