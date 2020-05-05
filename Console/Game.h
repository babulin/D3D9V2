#pragma once
#include "IGame.h"
#include <iostream>
using namespace AEngine;

class Game : public IGame {
public:
	// ͨ�� IGame �̳�
	Game() {
		std::cout << "Game()��ʼ��" << std::endl;
	}
	~Game() {
		std::cout << "~Game()����" << std::endl;
	}
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};