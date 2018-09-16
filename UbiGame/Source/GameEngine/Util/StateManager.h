#pragma once

#include "State.h"
#include <memory>
#include <vector>

namespace GameEngine
{
	class StateManager
	{
	public:
		~StateManager();
		static StateManager* GetInstance()
		{
			if (!sm_instance) sm_instance = new StateManager();
			return sm_instance;
		}
		State* state;

	private:
		StateManager();
		static StateManager* sm_instance;
	};
}
