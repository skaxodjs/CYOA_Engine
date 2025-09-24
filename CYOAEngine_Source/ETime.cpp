#include "ETime.h"

namespace CYOA
{
	LARGE_INTEGER ETime::CpuFrequency = {};
	LARGE_INTEGER ETime::Prevfrequency = {};
	LARGE_INTEGER ETime::CurrentFrequency = {};
	float ETime::DeltaTimeValue = 0.0f;

	void ETime::Initailize()
	{
		//Cpu의 고유 진동수, 타이머가 1초에 몇번 tick하는지 반환
		QueryPerformanceFrequency(&CpuFrequency);
		//프로그램이 시작되었을 때 현재 진동수, 현재 시점의 타이머 카운트 수 반환
		QueryPerformanceCounter(&Prevfrequency);
	}

	void ETime::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		// 현재 tick 횟수 - 이전 프레임의 tick 횟수, 
		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - Prevfrequency.QuadPart);
		// 한 프레임의 tick 횟수 / 1초당 Cpu가 tick하는 횟수, 즉 1프레임에 몇초가 지났는지 확인할 수 있게 해주는 값
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		Prevfrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void ETime::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Fps : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);

	}
}