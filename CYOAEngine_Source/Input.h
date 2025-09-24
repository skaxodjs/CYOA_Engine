#pragma once
#include "Common.h"
namespace CYOA
{
	enum class eKeyState
	{
		None,
		Down,
		Pressed,
		Up,
		
	};
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static void Initailize();
		static void Update();

		static bool GetKey(eKeyCode code);
		static bool GetKeyUp(eKeyCode code);
		static bool GetKeyDown(eKeyCode code);




	private:
		
	private:
		static std::vector<Key> mKeys;
	};
}



