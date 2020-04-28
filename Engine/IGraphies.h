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
        IGameWnd* pGameWnd;             //��������
        LPDIRECT3D9 m_d3d9;				//d3d����
        LPD3DXFONT m_d3dFont;			//���ֶ���
        LPDIRECT3DDEVICE9 m_d3dDevice;	//�豸����
    public:
        //��ʼ��ͼ�νӿ�
        virtual ExCode Init() = 0;

        //
    };
}