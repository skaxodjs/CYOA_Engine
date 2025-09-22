#pragma once
#include "Common.h"
namespace CYOA
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();

		void Render(HDC hdc);


	private:
		float mX;
		float mY;

	};

}

