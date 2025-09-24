#include "Input.h"

namespace CYOA
{
	std::vector<Input::Key> Input::Keys = {};
	int ASCII[(UINT)eKeyCode::End] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP,
	};

	void Input::Initailize()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}

	void Input::Update()
	{
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Pressed; // 만약 키가 눌려졌을 때, 전 프레임에 이미 눌려진 상태일 경우 Pressed(눌려져있음)
				}
				else
				{
					Keys[i].state = eKeyState::Down; // 만약 키가 눌려졌을 때, 전 프레임에서 키가 눌려지지 않은 상태일 경우 Down(이제 막 누름)
				}
				Keys[i].bPressed = true;
			}
			else
			{
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Up; // 만약 키가 떨어져 있을 때, 전 프레임에서 키가 눌려진 상태일 경우  Up(방금 뗌)
				}
				else
				{
					Keys[i].state = eKeyState::None; //만약 키가 떨어져 있을 때, 전 프레임에서도 키가 떨어져 있는 경우 None(아무 상태도 아님)
				}
				Keys[i].bPressed = false;
			}
		}
	}


	bool Input::GetKey(eKeyCode code)
	{
		return Keys[(UINT)code].state == eKeyState::Pressed;
	}
	bool Input::GetKeyDown(eKeyCode code)
	{
		return Keys[(UINT)code].state == eKeyState::Down;
	}
	bool Input::GetKeyUp(eKeyCode code)
	{
		return Keys[(UINT)code].state == eKeyState::Up;
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}

	void Input::updateKeys()
	{

	}

	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keyCode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}

	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}
		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			key.state = eKeyState::None;
		}
		key.bPressed = false;
	}



}