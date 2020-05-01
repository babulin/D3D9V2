#pragma once
#include "IGraphies.h"
namespace AEngine {

	class Graphies{
		
	private:
		IGraphies* _graphies;

	public:
		Graphies();
		~Graphies();

		bool Init();
		void Draw();
		IGraphies& Get();
	};
}