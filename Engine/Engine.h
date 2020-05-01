#pragma once
#include "Common.h"
#include "IGameWnd.h"	//����
#include "Graphies.h"	//��ͼ

using namespace AhlinI;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;		//��Ϸ����
		Graphies* pGraphies;	//��ͼ����
		frameCallback framFunc;	//�ص�����
	public:
		Engine();
		ExCode Init();	//��ʼ��
		void Run();		//��Ⱦ
		void Close();	//�ر�
		void SetCallBack(frameCallback callback) { framFunc = callback; };

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

		//����
		void SetSpirit();
	};

	//��������
	AHLIN_API Engine* Engine_Start(const int ver);
}
