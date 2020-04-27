#pragma once
#include <string>
using std::string;
/**+-----------------------------------------------
 * | �쳣���� �����
 * |<����>
 * +-----------------------------------------------
 */
namespace AhlinI {

	//�쳣��
	enum ExCode
	{
		EX_ERROR = 0,	//����
		EX_WARN = 1,	//����
		EX_OK = 2,		//��ȷ
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