#include "Graphies.h"
#include "D3D9.h"
#include "OpenGL.h"

namespace AEngine {

	Graphies::Graphies()
	{
		#if AGE_GRAPHIES == 1
		_graphies = new D3D9();
		#elif AGE_GRAPHIES == 2
		_graphies = new OpenGL();
		#endif
	}

	bool Graphies::Init()
	{

		if (_graphies == nullptr || _graphies->Init() == EX_FAIL)
		{
			return false;
		}
		return true;
	}

	void Graphies::Draw()
	{
		_graphies->Draw();
	}

	IGraphies& Graphies::Get()
	{
		return *_graphies;
	}

	Graphies::~Graphies()
	{
		if (_graphies != nullptr)
		{
			delete _graphies;
		}
	}
}
