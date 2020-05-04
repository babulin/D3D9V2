#pragma once
#include "Graphies.h"

namespace AEngine {

	class AHLIN_API Spirit : public Graphies {
	private:
		wchar_t file[255];
	public:
		Spirit(const wchar_t file[]);
		~Spirit();
		void Load();
		void Show(float wo, float ho, float x, float y);

	};
}