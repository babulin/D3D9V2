#include "SceneSelRole.h"
#include <iostream>

bool SceneSelRole::Init()
{
	std::cout << std::endl << "[" << this << "]" << "SceneSelRole::Init()\t" << std::endl;

	//╪сть
	UICode g_uiCode;
	mBmp = new DataBmp("Data\\ui",g_uiCode.BG3);

	return true;
}

bool SceneSelRole::Update()
{
	return true;
}

bool SceneSelRole::Show()
{
	mBmp->Draw();
	return true;
}

SceneSelRole::~SceneSelRole()
{
	std::cout << "[X]" << "[" << this << "]" << "SceneSelRole::~SceneSelRole()\t" << std::endl;
	delete mBmp;
}
