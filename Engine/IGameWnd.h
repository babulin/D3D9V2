#pragma once
#include <Windows.h>
/**+-----------------------------------------------
 * | ��Ϸ���� �����
 * |<����DirectX OpenGL�ӿ�>
 * +-----------------------------------------------
 */
namespace AhlinI {

	class IGameWnd {
    protected:
        HWND hwnd;
        float width;
        float height;
    public:
        virtual void CreateWnd() = 0;
        virtual void SetSize(float _width, float _height) = 0;
	};
}