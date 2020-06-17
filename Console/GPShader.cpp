#include "GPShader.h"
GPShader::GPShader(const TCHAR _file[])
{
	std::cout << "[" << this << "]" << "GPShader::GPShader()\t" << std::endl;
	m_d3dDevice = GetDevice();
	lstrcpy(file, _file);
	//Load();
	LoadCSO();
}


GPShader::~GPShader()
{
	std::cout << "[X]" << "[" << this << "]" << "GPShader::~GPShader()\t" << std::endl;
	if (mConstTable != nullptr)
	{
		mConstTable->Release();
	}

	if (mPixelShader != nullptr)
	{
		mPixelShader->Release();
	}
}

void GPShader::Load()
{
	//---------------------------------------------------
	LPD3DXBUFFER shader = 0;
	LPD3DXBUFFER errorBuffer = 0;


	//������ɫ��
	HRESULT hr = D3DXCompileShaderFromFile(file, 0, 0, "main", "ps_3_0", D3DXSHADER_DEBUG, &shader, &errorBuffer, &mConstTable);
	if (errorBuffer)
	{
		MessageBox(NULL, (LPCWSTR)errorBuffer->GetBufferPointer(), 0, 0);
		errorBuffer->Release();
	}

	if (FAILED(hr))
	{
		MessageBox(NULL, L"D3DXCompileShaderFromFile - failed", 0, 0);
		return;
	}

	//����������ɫ��
	hr = m_d3dDevice->CreatePixelShader((DWORD*)shader->GetBufferPointer(), &mPixelShader);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"CreatePixelShader - failed", 0, 0);
		return;
	}

	shader->Release();
}

void GPShader::LoadCSO()
{
	FILE* fp;
	fopen_s(&fp, "pixel.bat", "rb");

	//ƫ�Ƶ���β
	fseek(fp, 0, SEEK_END);
	//��ȡ��С
	int size = ftell(fp);
	//�����ռ��С
	byte* buf = new byte[size];
	//ƫ�Ƶ�ͷ
	fseek(fp, 0, SEEK_SET);
	//�ڴ����
	memset(buf, 0, size);
	//��ȡ����
	size_t nRead = fread(buf, sizeof(byte), size, fp);

	//����������ɫ��
	HRESULT hr = m_d3dDevice->CreatePixelShader((DWORD*)buf, &mPixelShader);
	if (FAILED(hr))
	{
		MessageBox(NULL, L"CreatePixelShader - failed", 0, 0);
		return;
	}

	D3DXGetShaderConstantTable((DWORD*)buf, &mConstTable);

	delete[] buf;
	fclose(fp);
}



void GPShader::SetColorToColor(D3DXVECTOR4 _DstColor, D3DXVECTOR4 _SrcColor,float _speed)
{
	mDstColor = _DstColor - D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	mSrcColor = _SrcColor - D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
	speed = _speed;
}

void GPShader::SetPixelShader()
{
	//����
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	mConstTable->SetMatrix(m_d3dDevice, "matWorld", &matWorld);

	//float4 ���� ƽ��
	mSrcColor.x = addFloat(mDstColor.x, mSrcColor.x);
	mSrcColor.y = addFloat(mDstColor.y, mSrcColor.y);
	mSrcColor.z = addFloat(mDstColor.z, mSrcColor.z);
	mSrcColor.w = addFloat(mDstColor.w, mSrcColor.w);

	mConstTable->SetFloatArray(m_d3dDevice, "matTran", (float*)&mSrcColor, 4);

	//ʹ��������ɫ��
	m_d3dDevice->SetPixelShader(mPixelShader);
}

bool GPShader::hasMask()
{
	if (mSrcColor == mDstColor)
	{
		return true;
	}
	return false;
}

float GPShader::addFloat(float df,float sf)
{
	if (df == sf){
		return sf;
	}

	float fh = df - sf > 0.0f ? 1.0f : -1.0f;
	if (fabs(df - sf) < 0.01f)
	{
		sf = df;
	}
	else {
		sf = sf + speed * fh;
	}
	return sf;
}
