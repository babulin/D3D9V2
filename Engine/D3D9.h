#pragma once
#include "Common.h"
#include "GameWnd.h"

namespace AEngine {

	class D3D9{
	public:
		GameWnd* pGameWnd;				//��������
		IDirect3D9* m_d3d9;				//d3d����
		IDirect3DDevice9* m_d3dDevice;	//�豸����
	private:
		static D3D9* pD3D9;
		D3D9();
	public:
		//static
		static D3D9* GetInstance();	//��ȡ����
		
		//public
		void SetWnd(GameWnd* _gameWnd);	//���ô��ڶ���
		bool Init();					//��ʼ��
		void BeginScene();				//��ʼ
		void EndScene();				//����
		~D3D9();						//����
	};
}