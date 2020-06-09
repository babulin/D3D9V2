#pragma once
#include <Windows.h>
#include <string>
using std::wstring;

namespace AEngine {
	class GameWnd {
	public:
		HWND hwnd;          //���ھ��
		RECT wndRect;       //������Ļλ��
		RECT clientRect;    //�ͻ�������
		int width;			//���ڿ�
		int height;			//���ڸ�
		wstring title;      //���ڱ���
		POINT mMouse;       //���
		HINSTANCE hInstance;//ʵ�����
		static GameWnd* gGameWnd;//��������
	private:
		GameWnd();
	public:
		//static
		static GameWnd* CreateWnd();	//��õ���

		//public
		void SetSize(int width, int height);	//���ô�С
		void SetTitle(wstring title);			//���ñ���
		bool Create();							//��������
		void Update();							//������ʾ
		bool GetMsg();							//��Ϣ����
		static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		~GameWnd();								//����
	};
}