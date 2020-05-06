#pragma once
#include "IGame.h"
#include <iostream>
using namespace AEngine;

class Game : public IGame {
public:
	// ͨ�� IGame �̳�
	Game() {
		std::cout << "[" << this << "]" << "Game()��ʼ��" << std::endl;
	}
	~Game() {
		std::cout << "[" << this << "]" << "[x]Game::~Game()����" << std::endl;
	}
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};