#pragma once
#include "Common.h"
#include "IGameWnd.h"

using namespace AhlinI;
//using AhlinI::ExCode;
//using AhlinI::IGameWnd;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;	//��Ϸ����
		CALLFUNC render;
	public:
		Engine();
		ExCode Init(HINSTANCE hInst);	//��ʼ��
		bool Run();		//��Ⱦ
		void Close();	//�ر�
		void SetCallBack(CALLFUNC callback) { render = callback; };
		//��������
		void SetWndSize(float width, float height) { pGameWnd->SetSize(width, height); }	//���ô��ڴ�С
		void SetTitle(wstring title) { pGameWnd->SetTitle(title); }	//���ñ���
	};

	//��������
	AHLIN_API Engine* Engine_Start();
}
