#pragma once

#include "Common.h"

namespace CYOA
{
	class ETime
	{
	public:
		static void Initailize();
		static void Update();
		static void Render(HDC hdc);

		static float DeltaTime() { return DeltaTimeValue; }

	private:

		static LARGE_INTEGER CpuFrequency;
		static LARGE_INTEGER Prevfrequency;
		static LARGE_INTEGER CurrentFrequency;


		static float DeltaTimeValue;
	};
}