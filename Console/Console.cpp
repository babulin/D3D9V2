#include <Engine.h>
#include <iostream>
using namespace std;
using namespace AEngine;

Engine* g_engine = nullptr;

bool FrameFunc() {
	//MessageBox(NULL, L"Show！", L"小兔叽!", MB_OK);

	//设置一个图片
	g_engine->SetSpirit();

	//GError e(ExCode::EX_FAIL, "啊啊啊啊\n");
	//throw e;

	//返回true [false 则结束]
	return true;
}

int main(){

	cout << "AEngine Start...." << endl;

	//引擎点火
	g_engine = Engine_Start(AGE_VERSION);

	//设置标题
	g_engine->SetTitle(L"Ahlin'sGE D3D9 V2.1.0");
	//设置窗口大小
	g_engine->SetWndSize(1024.0f, 768.0f);
	//设置回调函数
	g_engine->SetCallBack(FrameFunc);

	//启动引擎
	if (g_engine->Init() != ExCode::EX_OK) {
		MessageBox(NULL, L"引擎启动失败！", L"小兔叽!", MB_OK);
	}

	//运转
	try
	{
		g_engine->Run();
	}
	catch (GError e)
	{
		cout << e.GetMsg();
	}


	//结束
	g_engine->Close();

	cout << "AEngine Close...." << endl;
	return 0;
}