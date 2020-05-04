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
	g_engine = CreateEngine(AGE_VERSION);

	//设置标题
	g_engine->SetTitle(L"Ahlin'sGE D3D9 V2.1.0");
	//设置窗口大小
	g_engine->SetWndSize(1024.0f, 768.0f);

	//设置回调函数
	g_engine->SetCallBack(&gGame);

	//启动引擎
	if ( ! g_engine->Init()) {
		MessageBox(NULL, L"引擎启动失败！", L"小兔叽!", MB_OK);
	}

	//运转
	g_engine->Run();

	//结束
	g_engine->Close();

	cout << "AEngine Close...." << endl;

 	return 0;
}