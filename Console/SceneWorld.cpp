#include "SceneWorld.h"
#include <iostream>

bool SceneWorld::Init()
{
	std::cout << std::endl << "[" << this << "]" << "SceneWorld::Init()\t" << std::endl;

	//╪сть
	mSpirit = new Spirit(L"Data\\BG1.bmp");
	return true;
}

bool SceneWorld::Update()
{
	return true;
}

bool SceneWorld::Show()
{
	mSpirit->Show(1024.0f,768.0f);
	return true;
}

SceneWorld::~SceneWorld()
{
	std::cout << "[X]" << "[" << this << "]" << "SceneWorld::~SceneWorld()\t" << std::endl;
	delete mSpirit;
}
