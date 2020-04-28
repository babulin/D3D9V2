#pragma once
#include <string>
using std::string;
/**+-----------------------------------------------
 * | 异常处理 抽象层
 * |<基类>
 * +-----------------------------------------------
 */
namespace AhlinI {

	//异常码
	enum ExCode
	{
		EX_FAIL = 0,	//错误
		EX_OK = 1,		//正确
	};

	class GError {
		protected:
			string msg;
			ExCode code;
		public:
			GError(ExCode _code, string msg);
			string getMessage();
	};
}