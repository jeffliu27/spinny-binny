#pragma once
#include "GameEngine\Util\State.h"

namespace GameEngine
{
	class StartState : public State
	{
	public:
		StartState();
		~StartState();

		void init();
		void update(float dt);
		void render(float dt);
		void dispose();

	};
}

