#pragma once
#include "IGame.h"
using namespace AEngine;

class World : public IGame {
public:
	// ͨ�� IGame �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};