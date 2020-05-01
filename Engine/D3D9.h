#pragma once
#include "IGraphies.h"

namespace AEngine {

	class D3D9 : public IGraphies {
		// 通过 IGraphies 继承
		virtual ExCode Init() override;

		// 通过 IGraphies 继承
		virtual void SetSpirit() override;

		// 通过 IGraphies 继承
		virtual void Draw() override;

		~D3D9();
	};
}