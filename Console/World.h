#pragma once
#include "IGame.h"
using namespace AEngine;

class World : public IGame {
public:
	// Í¨¹ý IGame ¼Ì³Ð
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};