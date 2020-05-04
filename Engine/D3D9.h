#pragma once
#include "Common.h"
#include "IGameWnd.h"

namespace AEngine {

	class D3D9{
	public:
		IGameWnd* pGameWnd;				//依赖窗口
		IDirect3D9* m_d3d9;				//d3d对象
		IDirect3DDevice9* m_d3dDevice;	//设备对象
	private:
		static D3D9* pD3D9;
		D3D9() {};
		static int Ref;
	public:

		static D3D9* GetInstance();

		//设置窗口对象
		void SetWnd(IGameWnd* pGameWnd) { 
			this->pGameWnd = pGameWnd; 
		};
		
		//引用计数
		void AddRef() { 
			Ref++; 
		};

		//释放
		void Release() { 
			Ref--; 

			std::cout << "D3D9:" << this << "  Ref:" << Ref << std::endl;

			if (!Ref) 
			{ 
				delete this; 
			} 
		};
		//初始化
		bool Init();
		//渲染实现
		void BeginScene();
		void EndScene();
		//析构
		~D3D9();
	};
}