#pragma once
#include "Common.h"
#include "IGameWnd.h"	//����
#include "IGraphies.h"	//��ͼ

using namespace AhlinI;
//using AhlinI::ExCode;
//using AhlinI::IGameWnd;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;		//��Ϸ����
		IGraphies* pGraphies;	//��ͼ�ӿ�
		frameCallback framFunc;	//�ص�����
	public:
		Engine();
		ExCode Init();	//��ʼ��
		void Run();		//��Ⱦ
		void Close();	//�ر�
		void SetCallBack(frameCallback callback) { framFunc = callback; };

		//��������
		void SetWndSize(float width, float height) { pGameWnd->SetSize(width, height); }	//���ô��ڴ�С
		void SetTitle(wstring title) { pGameWnd->SetTitle(title); }	//���ñ���

		//����
		void SetSpirit() { pGraphies->SetSpirit(); };
	};

	//��������
	AHLIN_API Engine* Engine_Start(const int ver);
}
