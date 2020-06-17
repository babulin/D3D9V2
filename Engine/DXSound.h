#pragma once
#include "Common.h"

namespace AEngine {

	// .WAV file header
	struct WAVEHEADER
	{
		char    riff_sig[4];            // 'RIFF'
		long    waveform_chunk_size;    // 8
		char    wave_sig[4];            // 'WAVE'
		char    format_sig[4];          // 'fmt ' (notice space after)
		long    format_chunk_size;      // 16;
		short   format_tag;             // WAVE_FORMAT_PCM
		short   channels;               // # of channels
		long    sample_rate;            // sampling rate
		long    bytes_per_sec;          // bytes per second
		short   block_align;            // sample block alignment
		short   bits_per_sample;        // bits per second
		char    data_sig[4];            // 'data'
		long    data_size;              // size of waveform data
	};

	class AHLIN_API DXSound {
	public:
		LPDIRECTSOUND8			g_pDirectSound = nullptr;
		LPDIRECTSOUNDBUFFER     g_pPrimaryBuffer = NULL;
		LPDIRECTSOUNDBUFFER8    g_pSecondaryBuffer = NULL;
	private:
		DXSound();
		static DXSound* pDSound;
	public:
		//µ¥ÀýÄ£Ê½
		static DXSound* GetInstance();

		bool Init(HWND hwnd);
		void Load(const char* file);
		void SetVolume(int volume);
		void Play();
		void Stop();
	};
}