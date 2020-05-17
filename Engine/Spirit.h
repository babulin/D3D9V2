#pragma once
#include "Graphies.h"
#include "EngineConfig.h"

namespace AEngine {

	class AHLIN_API Spirit : public Graphies {
	public:
		Spirit(const wchar_t file[]);
		Spirit();
		~Spirit();
		void Load(const wchar_t file[]);
		void Load(const wchar_t file[], const wchar_t file_2[]);
		void Show(float wo, float ho, float x = 0.0f, float y = 0.0f);

	};
}