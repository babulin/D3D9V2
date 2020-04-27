#pragma once
#include "Common.h"
#include "IGameWnd.h"

using AhlinI::ExCode;
using AhlinI::IGameWnd;

namespace AEngine {

	class AHLIN_API Engine {
	private:
		IGameWnd* pGameWnd;	//��Ϸ����
	public:
		Engine();
		ExCode Init();	//��ʼ��
		void Run();		//��Ⱦ
		void Close();	//�ر�

		void SetWndSize(float width,float height);	//���ô��ڴ�С
	};

	//��������
	AHLIN_API Engine* Engine_Start();
}
