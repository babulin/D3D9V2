#include <Engine.h>
#include <iostream>
#include "Game.h"
using namespace std;
using namespace AEngine;

Game gGame;
Engine* g_engine = nullptr;

int main(){

	cout << "AEngine Start...." << endl;

	//引擎点火
	g_engine = Engine::CreateEngine(AGE_VERSION);

	//设置标题
	g_engine->SetTitle(L"Ahlin'sGE D3D9 V2.2.0");
	//设置窗口大小
	g_engine->SetSize(1024, 768);

	//设置游戏类
	g_engine->SetGame(&gGame);

	//启动引擎
	if ( ! g_engine->Init()) {
		MessageBox(NULL, L"引擎启动失败！", L"小兔叽!", MB_OK);
		return 0;
	}

	//运转
	g_engine->Run();

	//结束
	g_engine->Close();

	cout << "AEngine Close...." << endl;

 	return 0;
}