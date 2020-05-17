#pragma once
#include "IScene.h"
#include "DataBmp.h"
using namespace AEngine;

class SceneLogin : public IScene{
public:
	DataBmp* mBmp;
	GPShader* mPSShader;
public:
	// ͨ�� IScene �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneLogin();
};