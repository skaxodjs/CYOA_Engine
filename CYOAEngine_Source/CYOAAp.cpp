#include "CYOAAp.h"


namespace CYOA
{
	CYOAAp::CYOAAp()
		: mHwnd(nullptr)
		, mHdc(nullptr)

	{

	}
	CYOAAp::~CYOAAp()
	{

	}

	void CYOAAp::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

	}

	void CYOAAp::Run()
	{
		Update();
		LateUpdate();
		Render();

	}

	void CYOAAp::Update()
	{
		mPlayer.Update();
	}


	void CYOAAp::LateUpdate()
	{
		mPlayer.LateUpdate();
	}

	void CYOAAp::Render()
	{
		mPlayer.Render(mHdc);
	}
	
}