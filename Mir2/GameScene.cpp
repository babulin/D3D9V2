#include "GameScene.h"
#include "GStartUp.h"
GStartUp gStartUp;
void GameScene::Init()
{
	gStartUp.Init();
}

//��½����
void GameScene::StartUp()
{
	gStartUp.Show();
}

void GameScene::SignIn()
{
	
}


