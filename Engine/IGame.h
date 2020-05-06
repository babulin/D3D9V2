#pragma once
namespace AEngine{
	class IGame {
	public:
		virtual bool Init() = 0;
		virtual bool Update() = 0;
		virtual bool Show() = 0;
		virtual ~IGame() {};
	};
}