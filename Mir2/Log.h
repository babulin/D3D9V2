#pragma once
#include "Common.h"

class Log
{
public:
	Log() {};
	inline static void Debug(const char* msg) {
		if ( ! HAS_DEBUG){
			return;
		}
		OutputDebugStringA(msg);
	};

	~Log() {

	};


};