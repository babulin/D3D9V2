#include "SceneLogin.h"
#include "DXSound.h"
#include <iostream>

DXSound* g_pSound;
bool SceneLogin::Init()
{
	std::cout << std::endl << "[" << this << "]" << "SceneLogin::Init()\t" << std::endl;

	//����Ч��
	mPSShader = new GPShader(TEXT("PS_01.hlsl"));
	mPSShader->SetColorToColor(COLORF_WHITE, COLORF_BLACK, 0.01f);

	//��ʼ��ͼƬ
	UICode g_uiCode;
	mBmp = new DataBmp("Data\\ui", g_uiCode.BG1);
	mBmp->SetPSShader(mPSShader);//����Ч��

	//��ʼ����Ƶ
	g_pSound = DXSound::GetInstance();
	g_pSound->Load("Wav\\Login1.wav");
	g_pSound->Play();

	return true;
}

bool SceneLogin::Update()
{
	if (GetKeyState(DIK_4))
	{
		MessageBox(nullptr, L"�ɶ���������Ȼ������4", L"������ʾ", 0);
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
