#pragma once
#include "IScene.h"
#include "Spirit.h"
using namespace AEngine;

class SceneWorld : public IScene {
public:
	Spirit* mSpirit;
public:
	// Í¨¹ý IScene ¼Ì³Ð
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
	~SceneWorld();
};