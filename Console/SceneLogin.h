#pragma once
#include "IScene.h"
#include "Spirit.h"
using namespace AEngine;

class SceneLogin : public IScene{
public:
	Spirit *pSpirit;
	Spirit mSpirit;
public:
	// ͨ�� IScene �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneLogin();
};