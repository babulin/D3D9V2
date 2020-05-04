#include "Graphies.h"
#include "D3D9.h"

namespace AEngine {

	//构造
	Graphies::Graphies()
	{
		#if AGE_GRAPHIES == 1
		_graphies = D3D9::GetInstance();
		#elif AGE_GRAPHIES == 2
		//_graphies = new OpenGL();
		#endif
	}

	LPDIRECT3DDEVICE9 Graphies::GetDevice()
	{
		return _graphies->m_d3dDevice;
	}

	//获取渲染器
	D3D9* Graphies::Get()
	{
		return _graphies;
	}

	//析构
	Graphies::~Graphies()
	{
		_graphies->Release();
	}
}
