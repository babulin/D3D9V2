#pragma once
#include "IScene.h"
#include "DataBmp.h"
using namespace AEngine;

class SceneLogin : public IScene{
public:
	DataBmp* mBmp;
	GPShader* mPSShader;
public:
	// Í¨¹ý IScene ¼Ì³Ð
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneLogin();
};