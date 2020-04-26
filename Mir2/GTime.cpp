#include "GTime.h"

ULONGLONG GTime::s_tNowTime = 0;
ULONGLONG GTime::s_tPrevTime = 0;
ULONGLONG GTime::s_tInitTime = GetTickCount64();

GTime::GTime()
{
	m_tPrevTime = s_tNowTime;
}

GTime::~GTime()
{
}

void GTime::run()
{
	s_tNowTime = (GetTickCount64() - s_tInitTime);
}

void GTime::over() {
	s_tPrevTime = s_tNowTime;
}

bool GTime::CountDown(int time)
{
	if (s_tNowTime - m_tPrevTime > time)
	{
		m_tPrevTime = s_tNowTime;
		return true;
	}
	return false;
}

float GTime::GetCountDown()
{
	float frameTime = (s_tNowTime - s_tPrevTime) * 0.001f;

	if (HAS_DEBUG)
	{
		char buf[MSG_SIZE] = { 0 };
		sprintf_s(buf, "[frame] %0.4f \n", frameTime);
		Log::Debug(buf);
	}

	return frameTime;
}


