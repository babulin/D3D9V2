#pragma once
#include "Common.h"
#include "IGameWnd.h"	//����
#include "D3D9.h"		//��Ⱦ��
#include "IGame.h"		//��Ϸ

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;		//��Ϸ����
		D3D9* pD3D9;			//��Ⱦ��
		IGame* pGame;			//�ص���
	public:
		//����
		Engine();
		//��ʼ��
		bool Init();
		//����
		void Run();	
		//�ر�
		void Close();	

		//���ûص���
		void SetCallBack(IGame* _game) { 
			pGame = _game; 
		};

		//���ô��ڴ�С
		void SetWndSize(float width, float height) 
		{ 
			pGameWnd->SetSize(width, height); 
		}	

		//���ñ���
		void SetTitle(wstring title) 
		{ 
			pGameWnd->SetTitle(title); 
		}	
	};

	//��������
	AHLIN_API Engine* CreateEngine(const int ver);
}
