#include "SceneLogin.h"
#include "DXSound.h"
#include <iostream>

DXSound* g_pSound;
bool SceneLogin::Init()
{
	std::cout << std::endl << "[" << this << "]" << "SceneLogin::Init()\t" << std::endl;

	//渐变效果
	mPSShader = new GPShader(TEXT("PS_01.hlsl"));
	mPSShader->SetColorToColor(COLORF_WHITE, COLORF_BLACK, 0.01f);

	//初始化图片
	UICode g_uiCode;
	mBmp = new DataBmp("Data\\ui", g_uiCode.BG1);
	mBmp->SetPSShader(mPSShader);//渐变效果

	//初始化音频
	g_pSound = DXSound::GetInstance();
	g_pSound->Load("Wav\\Login1.wav");
	g_pSound->Play();

	return true;
}

bool SceneLogin::Update()
{
	if (GetKeyState(DIK_4))
	{
		MessageBox(nullptr, L"可恶的人类你居然按下了4", L"按键提示", 0);
	}
	return true;
}

bool SceneLogin::Show()
{
	mBmp->Draw();
	return true;
}

SceneLogin::~SceneLogin()
{
	std::cout << "[X]" << "[" << this << "]" << "SceneLogin::~SceneLogin()\t" << std::endl;
	if (mBmp != nullptr)
	{
		delete mBmp;
	}

	g_pSound->Stop();
}
