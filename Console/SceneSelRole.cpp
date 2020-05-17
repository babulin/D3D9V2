#include "SceneSelRole.h"
#include <iostream>

bool SceneSelRole::Init()
{
	std::cout << "[" << this << "]" << "SceneSelRole::Init()\t" << std::endl;

	//╪сть
	mSpirit.Load(L"1.png");

	return true;
}

bool SceneSelRole::Update()
{
	return true;
}

bool SceneSelRole::Show()
{
	mSpirit.Show(800.0f, 600.0f, 0.0f, 0.0f);
	return true;
}

SceneSelRole::~SceneSelRole()
{
	std::cout << "[X]" << "[" << this << "]" << "SceneSelRole::~SceneSelRole()\t" << std::endl;
}
