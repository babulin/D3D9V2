#pragma once
#include "D3D9.h"
/**+----------------------------------
 * | 绘图类 <用于基类>
 * +----------------------------------
 */
namespace AEngine {

	class AHLIN_API Graphies{
		
	private:
		D3D9* _graphies;
	protected:
		IDirect3DTexture9* pTexture1;
		IDirect3DTexture9* pTexture2;
	public:
		Graphies();
		virtual ~Graphies();

		LPDIRECT3DDEVICE9 GetDevice();
		D3D9* Get();
	};
}