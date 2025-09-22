#pragma once
#include "Common.h"
#include "GameObject.h"
namespace CYOA
{
	class CYOAAp
	{
	public:
		CYOAAp();
		~CYOAAp();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();

		void Render();
	private:
		HWND mHwnd;
		HDC mHdc;
		GameObject mPlayer;
	};
}


