#include "Engine.h"
#include "GameWnd.h"
#include "D3D9.h"
#include "OpenGL.h"

using namespace AEngine;
using namespace AhlinI;

Engine* gEngine = nullptr;

//��������
Engine* AEngine::Engine_Start(const int ver)
{
	if (ver != AGE_VERSION)
	{
		return nullptr;
	}

	if (gEngine == nullptr)
	{
		gEngine = new Engine();
	}
	return gEngine;
}

Engine::Engine()
{
	pGameWnd = AhlinI::CreateWnd();
}

//---------------------------------------
//|��ʼ��
//---------------------------------------
ExCode Engine::Init()
{
	//��ʼ������
	HINSTANCE hInst = GetModuleHandle(nullptr);
	pGameWnd->Init(hInst);

	//��ʼ����Ⱦģ��
	pGraphies = new Graphies();
	pGraphies->Get().SetWnd(pGameWnd);
	if ( ! pGraphies->Init())
	{
		return EX_FAIL;
	}

	//��ʼ������

	return EX_OK;
}

//---------------------------------------
//| ����
//---------------------------------------
void Engine::Run()
{
	//ѭ��
	while (pGameWnd->GetMsg())
	{
		//�ص�
		if ( ! framFunc())
		{
			//����
			break;
		}

		//����
		pGraphies->Draw();
	}
}

void Engine::Close()
{
	if (pGameWnd != nullptr)
	{
		delete pGameWnd;
		pGameWnd = nullptr;
	}

	if (pGraphies != nullptr)
	{
		delete pGraphies;
		pGraphies = nullptr;
	}

	delete this;
}

void AEngine::Engine::SetSpirit()
{
	pGraphies->Get().SetSpirit();
}
