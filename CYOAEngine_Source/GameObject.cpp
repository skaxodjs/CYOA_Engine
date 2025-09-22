#include "GameObject.h"

namespace CYOA
{
	GameObject::GameObject()
	{
		mX = 0;
		mY = 0;
	}
	GameObject::~GameObject()
	{

	}

	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX += -0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY += -0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC mHdc)
	{
		Rectangle(mHdc, 500 + mX, 500 + mY, 600 + mX, 600 + mY);
	}

}