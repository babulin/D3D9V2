#include "DXSound.h"
namespace AEngine {

	DXSound* DXSound::pDSound = nullptr;

	DXSound* DXSound::GetInstance()
	{
		if (pDSound == nullptr)
		{
			pDSound = new DXSound();
		}

		return pDSound;
	}

	DXSound::DXSound()
	{

	}

	bool DXSound::Init(HWND hwnd)
	{
		// 创建IDirectSound8接口
		DirectSoundCreate8(NULL, &g_pDirectSound, NULL);
		g_pDirectSound->SetCooperativeLevel(hwnd, DSSCL_NORMAL);


		return true;
	}

	void DXSound::Load(const char* file)
	{
        // 读取WAV音频信息
        WAVEHEADER wave_header;
        ::ZeroMemory(&wave_header, sizeof(WAVEHEADER));
        FILE* fp;
        fopen_s(&fp,file, "rb");

        fread((void*)&wave_header, 1, sizeof(WAVEHEADER), fp);

        // 创建主音频缓存和辅助音频缓存
        WAVEFORMATEX  wave_format;
        ZeroMemory(&wave_format, sizeof(WAVEFORMATEX));
        wave_format.wFormatTag = WAVE_FORMAT_PCM;
        wave_format.nChannels = wave_header.channels;
        wave_format.nSamplesPerSec = wave_header.sample_rate;
        wave_format.wBitsPerSample = wave_header.bits_per_sample;
        wave_format.nBlockAlign = wave_format.wBitsPerSample / 8 * wave_format.nChannels;
        wave_format.nAvgBytesPerSec = wave_format.nSamplesPerSec * wave_format.nBlockAlign;

        DSBUFFERDESC  ds_buf_desc;
        ZeroMemory(&ds_buf_desc, sizeof(DSBUFFERDESC));
        ds_buf_desc.dwSize = sizeof(DSBUFFERDESC);
        ds_buf_desc.dwFlags = DSBCAPS_CTRLVOLUME;
        ds_buf_desc.dwBufferBytes = wave_header.data_size;
        ds_buf_desc.lpwfxFormat = &wave_format;

        g_pDirectSound->CreateSoundBuffer(&ds_buf_desc, &g_pPrimaryBuffer, NULL);
        g_pPrimaryBuffer->QueryInterface(IID_IDirectSoundBuffer8, (void**)&g_pSecondaryBuffer);

        // 加载WAV音频数据
        char* ptr1, * ptr2;
        DWORD size1, size2;

        fseek(fp, sizeof(WAVEHEADER), SEEK_SET);
        g_pSecondaryBuffer->Lock(0, wave_header.data_size, (void**)&ptr1, &size1, (void**)&ptr2, &size2, 0);

        if (ptr1) fread(ptr1, 1, size1, fp);
        if (ptr2) fread(ptr2, 1, size2, fp);

        g_pSecondaryBuffer->Unlock(ptr1, size1, ptr2, size2);
        fclose(fp);
	}

    void DXSound::SetVolume(int volume)
    {
        g_pSecondaryBuffer->SetVolume(volume);
    }

    void DXSound::Play()
    {
        g_pSecondaryBuffer->Play(0, 0, DSBPLAY_LOOPING);
    }

    void DXSound::Stop()
    {
        g_pSecondaryBuffer->Stop();
        g_pSecondaryBuffer->Release();
        g_pPrimaryBuffer->Release();
    }




}
