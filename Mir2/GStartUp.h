#pragma once
#include "GScene.h"
#include "DataWzl.h"
#include "GPShader.h"

class GStartUp : virtual public GScene {
	UICode g_uiCode;
	DataBmp* g_BG1Bmp;
	DataBmp* g_BG2Bmp;
	DataBmp* g_Logo;
	GPShader* g_PSShader, * g_LogoPs;
	// «∑Ò≥ı ºªØ
	bool hasInit = false;
public:
	GStartUp();
	~GStartUp();
	virtual void Init();
	virtual void Show();
};