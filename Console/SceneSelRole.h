#pragma once
#include "IScene.h"
#include "DataBmp.h"
using namespace AEngine;

class SceneSelRole : public IScene {
public:
	DataBmp *mBmp;
public:
	// ͨ�� IScene �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneSelRole();
};