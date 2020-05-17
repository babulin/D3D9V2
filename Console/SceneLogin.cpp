#include "SceneLogin.h"
#include <iostream>

bool SceneLogin::Init()
{
	std::cout << std::endl << "[" << this << "]" << "SceneLogin::Init()\t" << std::endl;



	//渐变效果
	//mPSShader = new GPShader(TEXT("PS_01.hlsl"));
	//mPSShader->SetColorToColor(COLORF_BLACK, COLORF_WHITE, 0.01f);

	//初始化图片
	UICode g_uiCode;
	mBmp = new DataBmp("Data\\ui", g_uiCode.BG1);

	//mBmp->SetPSShader(mPSShader);//渐变效果

	return true;
}

bool SceneLogin::Update()
{
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
}
