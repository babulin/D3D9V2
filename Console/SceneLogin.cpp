#include "SceneLogin.h"
#include <iostream>


bool SceneLogin::Init()
{
	std::cout << "[" << this << "]" << "SceneLogin::Init()\t" << std::endl;

	//初始化一些资源
	//pSpirit = new Spirit();
	//pSpirit->Load(L"1.png", L"2.png");

	//加载
	mSpirit.Load(L"1.png");

	return true;
}

bool SceneLogin::Update()
{
	return true;
}

bool SceneLogin::Show()
{
	//pSpirit->Show(500.0f, 480.0f, 0.0f, 0.0f);
	mSpirit.Show(500.0f, 480.0f, 0.0f, 0.0f);
	return true;
}

SceneLogin::~SceneLogin()
{
	std::cout << "[X]" << "[" << this << "]" << "SceneLogin::~SceneLogin()\t" << std::endl;
}
