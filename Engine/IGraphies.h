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
        IGameWnd* pGameWnd;         //依赖窗口
        IDirect3D9* m_d3d9;				//d3d对象
        IDirect3DDevice9* m_d3dDevice;	    //设备对象
    public:
        virtual void SetWnd(IGameWnd* pGameWnd) { this->pGameWnd = pGameWnd; };
        //初始化图形接口
        virtual ExCode Init() = 0;

        virtual void SetSpirit() = 0;

        virtual void Draw() = 0;

        virtual ~IGraphies() {};
    };
}