#pragma once
#include "Common.h"
#include "GError.h"
#include "IGameWnd.h"

/**+-----------------------------------------------
 * | ͼ��API�����
 * |<����DirectX OpenGL�ӿ�>
 * +-----------------------------------------------
 */
using namespace AhlinI;
namespace AEngine {

    class IGraphies {
    protected:
        IGameWnd* pGameWnd;         //��������
        IDirect3D9* m_d3d9;				//d3d����
        IDirect3DDevice9* m_d3dDevice;	    //�豸����
    public:
        virtual void SetWnd(IGameWnd* pGameWnd) { this->pGameWnd = pGameWnd; };
        //��ʼ��ͼ�νӿ�
        virtual ExCode Init() = 0;

        virtual void SetSpirit() = 0;

        virtual void Draw() = 0;

        virtual ~IGraphies() {};
    };
}