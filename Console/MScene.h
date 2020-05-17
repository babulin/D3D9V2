#pragma once
#include "Config.h"
#include "SceneManage.h"
#include "SceneLogin.h"
#include "SceneSelRole.h"
#include "SceneWorld.h"

using namespace AEngine;

class MScene : public SceneManage {
private:
	static GAME_SCENE GameProgress;
	SceneLogin *mSLogin;
	SceneSelRole *mSelRole;
	SceneWorld *mWorld;
public:
	MScene();
	bool Init();
	bool Update();
	~MScene();
	void SetKey();
};