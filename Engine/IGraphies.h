#pragma once
#include "Common.h"
#include "GError.h"
#include "IGameWnd.h"

/**+-----------------------------------------------
 * | 图形API抽象层
 * |<面向DirectX OpenGL接口>
 * +-----------------------------------------------
 */
using namespace AhlinI;
namespace AEngine {

    class IGraphies {
    protected:
        IGameWnd* pGameWnd;             //依赖窗口
        LPDIRECT3D9 m_d3d9;				//d3d对象
        LPD3DXFONT m_d3dFont;			//文字对象
        LPDIRECT3DDEVICE9 m_d3dDevice;	//设备对象
    public:
        //初始化图形接口
        virtual ExCode Init() = 0;

        //
    };
}