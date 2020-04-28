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
		EX_FAIL = 0,	//����
		EX_OK = 1,		//��ȷ
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