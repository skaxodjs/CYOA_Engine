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
					Keys[i].state = eKeyState::Pressed; // ���� Ű�� �������� ��, �� �����ӿ� �̹� ������ ������ ��� Pressed(����������)
				}
				else
				{
					Keys[i].state = eKeyState::Down; // ���� Ű�� �������� ��, �� �����ӿ��� Ű�� �������� ���� ������ ��� Down(���� �� ����)
				}
				Keys[i].bPressed = true;
			}
			else
			{
				if (Keys[i].bPressed == true)
				{
					Keys[i].state = eKeyState::Up; // ���� Ű�� ������ ���� ��, �� �����ӿ��� Ű�� ������ ������ ���  Up(��� ��)
				}
				else
				{
					Keys[i].state = eKeyState::None; //���� Ű�� ������ ���� ��, �� �����ӿ����� Ű�� ������ �ִ� ��� None(�ƹ� ���µ� �ƴ�)
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