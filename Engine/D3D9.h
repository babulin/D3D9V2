#pragma once
#include "IGraphies.h"

namespace AEngine {

	class D3D9 : public IGraphies {
		// ͨ�� IGraphies �̳�
		virtual ExCode Init() override;

		// ͨ�� IGraphies �̳�
		virtual void SetSpirit() override;

		// ͨ�� IGraphies �̳�
		virtual void Draw() override;

		~D3D9();
	};
}