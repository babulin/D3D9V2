#include "Graphies.h"
#include "D3D9.h"

namespace AEngine {

	//����
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

	//��ȡ��Ⱦ��
	D3D9* Graphies::Get()
	{
		return _graphies;
	}

	//����
	Graphies::~Graphies()
	{
		_graphies->Release();
	}
}
