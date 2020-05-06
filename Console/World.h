#pragma once
#include "IGame.h"
#include <iostream>
using namespace AEngine;

class World : public IGame {
public:
	World() {
		std::cout << "[" << this << "]" << "World()��ʼ��" << std::endl;
	}
	~World() {
		std::cout << "[" << this << "]" << "[x]World::~World()����" << std::endl;
	}
	// ͨ�� IGame �̳�
	virtual bool Init() override;
	virtual bool Update() override;
	virtual bool Show() override;
};