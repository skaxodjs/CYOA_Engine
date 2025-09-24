#include "ETime.h"

namespace CYOA
{
	LARGE_INTEGER ETime::CpuFrequency = {};
	LARGE_INTEGER ETime::Prevfrequency = {};
	LARGE_INTEGER ETime::CurrentFrequency = {};
	float ETime::DeltaTimeValue = 0.0f;

	void ETime::Initailize()
	{
		//Cpu�� ���� ������, Ÿ�̸Ӱ� 1�ʿ� ��� tick�ϴ��� ��ȯ
		QueryPerformanceFrequency(&CpuFrequency);
		//���α׷��� ���۵Ǿ��� �� ���� ������, ���� ������ Ÿ�̸� ī��Ʈ �� ��ȯ
		QueryPerformanceCounter(&Prevfrequency);
	}

	void ETime::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);
		// ���� tick Ƚ�� - ���� �������� tick Ƚ��, 
		float differenceFrequency = static_cast<float>(CurrentFrequency.QuadPart - Prevfrequency.QuadPart);
		// �� �������� tick Ƚ�� / 1�ʴ� Cpu�� tick�ϴ� Ƚ��, �� 1�����ӿ� ���ʰ� �������� Ȯ���� �� �ְ� ���ִ� ��
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