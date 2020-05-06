#pragma once
#include "IGame.h"
#include <iostream>
using namespace AEngine;

class World : public IGame {
public:
	World() {
		std::cout << "[" << this << "]" << "World()初始化" << std::endl;
	}
	~World() {
		std::cout << "[" << this << "]" << "[x]World::~World()析构" << std::endl;
	}
	// 通过 IGame 继承
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};