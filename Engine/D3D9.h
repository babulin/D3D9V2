#pragma once
#include "Common.h"
#include "GameWnd.h"

namespace AEngine {

	class D3D9{
	public:
		GameWnd* pGameWnd;				//依赖窗口
		IDirect3D9* m_d3d9;				//d3d对象
		IDirect3DDevice9* m_d3dDevice;	//设备对象
	private:
		bool m_fullscreen = true;
		static D3D9* pD3D9;
		D3D9();
	public:
		//static
		static D3D9* GetInstance();	//获取单例
		
		//public
		void SetFullScreen(bool _full);
		void SetWnd(GameWnd* _gameWnd);	//设置窗口对象
		bool Init();					//初始化
		void BeginScene();				//开始
		void EndScene();				//结束
		~D3D9();						//析构
	};
}