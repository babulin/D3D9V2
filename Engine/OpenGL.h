#pragma once
#include "IGraphies.h"

namespace AEngine {

	class OpenGL : public IGraphies {
		// Í¨¹ý IGraphies ¼Ì³Ð
		virtual ExCode Init() override;

		virtual void SetSpirit() override;
		virtual void Draw() override;
	};
}