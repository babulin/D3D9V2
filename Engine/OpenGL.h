#pragma once
#include "IGraphies.h"

namespace AEngine {

	class OpenGL : public IGraphies {
		// ͨ�� IGraphies �̳�
		virtual ExCode Init() override;
	};
}