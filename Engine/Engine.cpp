#include "Engine.h"
#include "GameWnd.h"

using namespace AEngine;
using namespace AhlinI;

Engine* gEngine = nullptr;

//��������
Engine* AEngine::Engine_Start()
{
	if (gEngine == nullptr)
	{
		gEngine = new Engine();
	}
	return gEngine;
}

Engine::Engine()
{
	//����
	pGameWnd = AhlinI::CreateWnd();
}


ExCode Engine::Init(HINSTANCE hInst)
{
	//��ʼ������
	pGameWnd->Init(hInst);

	//��ʼ����Ⱦģ��

	return ExCode::EX_OK;
}

bool Engine::Run()
{
	//ѭ��
	while (pGameWnd->GetMsg())
	{
		//�ص�
		render();
	}
	return false;
}

void Engine::Close()
{
	if (pGameWnd != nullptr)
	{
		delete pGameWnd;
		pGameWnd = nullptr;
	}
}