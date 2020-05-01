#pragma once
#include "IGraphies.h"

namespace AEngine {

	class OpenGL : public IGraphies {
		// ͨ�� IGraphies �̳�
		virtual ExCode Init() override;

		virtual void SetSpirit() override;
		virtual void Draw() override;
	};
}