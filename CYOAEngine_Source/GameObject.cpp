#include "GameObject.h"
#include "Input.h"

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
		if (Input::GetKey(eKeyCode::A))
		{
			mX += -0.01f;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += 0.01f;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY += -0.01f;
		}
		if (Input::GetKey(eKeyCode::S))
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