#pragma once
/*+--------------------------------------
* | ��Ϸ�� <���ڹ�����Ϸ����>
* +--------------------------------------
*/
namespace AEngine{
	class IGame {
	public:
		virtual bool Init();
		virtual bool Update();
		virtual bool Show();
		bool SetSence();
		virtual ~IGame() {};
	};
}