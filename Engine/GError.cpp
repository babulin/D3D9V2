#include "GError.h"

AhlinI::GError::GError(ExCode _code, string _msg)
{
	code = _code;
	msg = _msg;
}

string AhlinI::GError::getMessage()
{
	return msg;
}
