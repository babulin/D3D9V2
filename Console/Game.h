#pragma once
#include "IGame.h"
using namespace AEngine;

class Game : public IGame {
public:
	// ͨ�� IGame �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};