#pragma once
#include "IGame.h"
#include <iostream>
using namespace AEngine;

class Game : public IGame {
public:
	// 通过 IGame 继承
	Game() {
		std::cout << "[" << this << "]" << "Game()初始化" << std::endl;
	}
	~Game() {
		std::cout << "[" << this << "]" << "[x]Game::~Game()析构" << std::endl;
	}
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};