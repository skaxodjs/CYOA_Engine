#include "CYOAAp.h"
#include "Input.h"
#include "ETime.h"

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
		Input::Initailize();
		ETime::Initailize();

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
		Input::Update();
		ETime::Update();
	}


	void CYOAAp::LateUpdate()
	{
		mPlayer.LateUpdate();
	}

	void CYOAAp::Render()
	{
		mPlayer.Render(mHdc);
		ETime::Render(mHdc);
	}
	
}