#pragma once
#include "IScene.h"
#include "Spirit.h"
using namespace AEngine;

class SceneWorld : public IScene {
public:
	Spirit* mSpirit;
public:
	// ͨ�� IScene �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneWorld();
};