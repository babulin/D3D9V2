#pragma once
#include "Config.h"
#include "SceneManage.h"
#include "SceneLogin.h"
#include "SceneSelRole.h"

using namespace AEngine;

class MScene : public SceneManage {
private:
	static GAME_SCENE GameProgress;
	SceneLogin *mSLogin;
	SceneSelRole *mSelRole;
public:
	MScene();
	bool Init();
	bool Update();
	~MScene();
};