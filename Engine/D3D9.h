#pragma once
#include "Common.h"
#include "IGameWnd.h"

namespace AEngine {

	class D3D9{
	public:
		IGameWnd* pGameWnd;				//��������
		IDirect3D9* m_d3d9;				//d3d����
		IDirect3DDevice9* m_d3dDevice;	//�豸����
	private:
		static D3D9* pD3D9;
		D3D9() {};
		static int Ref;
	public:

		static D3D9* GetInstance();

		//���ô��ڶ���
		void SetWnd(IGameWnd* pGameWnd) { 
			this->pGameWnd = pGameWnd; 
		};
		
		//���ü���
		void AddRef() { 
			Ref++; 
		};

		//�ͷ�
		void Release() { 
			Ref--; 

			std::cout << "D3D9:" << this << "  Ref:" << Ref << std::endl;

			if (!Ref) 
			{ 
				delete this; 
			} 
		};
		//��ʼ��
		bool Init();
		//��Ⱦʵ��
		void BeginScene();
		void EndScene();
		//����
		~D3D9();
	};
}