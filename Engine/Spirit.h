#pragma once
#include "Graphies.h"

namespace AEngine {

	class AHLIN_API Spirit : public Graphies {
	public:
		Spirit();
		~Spirit();
		void Load(const wchar_t file[]);
		void Load(const wchar_t file[], const wchar_t file_2[]);
		void Show(float wo, float ho, float x, float y);

	};
}