#include "Engine.h"
#include "D3D9.h"

namespace AEngine {

	//��ʼ����̬��Ա
	Engine* Engine::pEngine = nullptr;

	//��������
	 Engine* Engine::CreateEngine(const int ver)
	{
		if (ver != AGE_VERSION)
		{
			return nullptr;
		}

		if (pEngine == nullptr)
		{
			pEngine = new Engine();
		}
		return pEngine;
	}

	//---------------------------------------
	//| ���캯��
	//---------------------------------------
	Engine::Engine()
	{
		pGameWnd = GameWnd::CreateWnd();
		pD3D9 = D3D9::GetInstance();
		pD3D9->SetWnd(pGameWnd);
	}


	//---------------------------------------
	//| ��ʼ��
	//---------------------------------------
	bool Engine::Init()
	{
		//��ʼ������
		if ( ! pGameWnd->Create()) 
		{
			return false;
		}

		//��ʼ��DX9
		if ( ! pD3D9->Init())
		{
			return false;
		}

		//��ʼ����Ϸ��Դ
		if (pScene == nullptr)
		{
			MessageBox(nullptr, L"Engine::SetGame();��������һ��SceneManage��������!",L"error",MB_OK);
			return false;
		}

		if ( !pScene->Init()) {
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
			//�����������
			if ( ! pScene->Update())
			{
				break;
			}

			//ʵ������
			IScene *sence = pScene->GetScene();
			//std::cout << "sence:" << sence << std::endl;
			if (sence != nullptr)
			{
				//ʵ����������
				if ( ! sence->Update()) {
					break;
				}
			}

			//����
			pD3D9->BeginScene();

			//�ص�
			if (sence != nullptr)
			{
				//ʵ��������Ⱦ
				if ( ! sence->Show()) {
					break;
				}
			}

			pD3D9->EndScene();
		}
	}

	//---------------------------------------
	//| ����ر�
	//---------------------------------------
	void Engine::Close()
	{
		if (pGameWnd != nullptr)
		{
			delete pGameWnd;
			pGameWnd = nullptr;
		}

		if (pD3D9 != nullptr)
		{
			delete pD3D9;
			pD3D9 = nullptr;
		}

		delete this;
	}

	//---------------------------------------
	//| ��Ϸ������
	//---------------------------------------
	void Engine::SetGame(SceneManage* _scene)
	{
		pScene = _scene;
	}

	//���ñ���
	void Engine::SetTitle(wstring _title)
	{
		if (pGameWnd != nullptr)
			pGameWnd->SetTitle(_title);
	}

	//���ô�С
	void Engine::SetSize(int w, int h)
	{
		if (pGameWnd != nullptr)
			pGameWnd->SetSize(w, h);
	}
}