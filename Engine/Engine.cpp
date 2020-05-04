#include "Engine.h"
#include "D3D9.h"

namespace AEngine {

	Engine* gEngine = nullptr;

	//��������
	Engine* AEngine::CreateEngine(const int ver)
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

	//---------------------------------------
	//| ���캯��
	//---------------------------------------
	Engine::Engine()
	{
		pGameWnd = AEngine::CreateWnd();
	}

	//---------------------------------------
	//| ��ʼ��
	//---------------------------------------
	bool Engine::Init()
	{
		//��ʼ������
		HINSTANCE hInst = GetModuleHandle(nullptr);
		pGameWnd->Init(hInst);

		//��ʼ����Ⱦģ��
		pD3D9 = D3D9::GetInstance();
		pD3D9->SetWnd(pGameWnd);
		if ( !pD3D9->Init())
		{
			return false;
		}

		//��ʼ����Ϸ��Դ
		if (!pGame->Init()) {
			return false;
		}

		//��ʼ������

		return true;
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
			if ( !pGame->Update())
			{
				//����
				break;
			}

			//����
			pD3D9->BeginScene();

			//�ص�
			if (!pGame->Show())
			{
				//����
				break;
			}

			pD3D9->EndScene();
		}
	}

	void Engine::Close()
	{
		if (pGameWnd != nullptr)
		{
			delete pGameWnd;
			pGameWnd = nullptr;
		}

		if (pD3D9 != nullptr)
		{
			pD3D9->Release();
		}

		delete this;
	}
}