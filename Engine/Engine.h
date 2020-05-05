#pragma once
#include "Common.h"
#include "GameWnd.h"	//����
#include "D3D9.h"		//��Ⱦ��
#include "IGame.h"		//��Ϸ

namespace AEngine {

	class AHLIN_API Engine {
	private:
		GameWnd* pGameWnd;		//��Ϸ����
		D3D9* pD3D9;			//��Ⱦ��
		IGame* pGame;			//��Ϸ��

		static Engine* pEngine;	//���������
	private:
		Engine();
	public:
		//static
		static Engine* CreateEngine(const int ver);	//��������

		//engine
		bool Init();					//��ʼ��
		void Run();						//����
		void Close();					//�ر�

		//get
		void SetGame(IGame* _game);		//������Ϸ��

		//windows
		void SetTitle(wstring _title);
		void SetSize(int w, int h);
	};
}
