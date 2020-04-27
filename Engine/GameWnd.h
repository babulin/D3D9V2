#pragma once
#include "IGameWnd.h"

namespace AhlinI {
	class GameWnd : public IGameWnd {
		virtual void CreateWnd();
		virtual void SetSize(float _width,float _height);
	};
}