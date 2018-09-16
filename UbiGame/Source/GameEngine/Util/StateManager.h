#pragma once

#include "State.h"
#include <memory>
#include <vector>

namespace GameEngine
{
	typedef std::unique_ptr<State> StateRef;

	class StateManager
	{
	public:
		~StateManager();
		static StateManager* GetInstance()
		{
			if (!sm_instance) sm_instance = new StateManager();
			return sm_instance;
		}
		void AddState(StateRef newState, bool isReplacing = true);
		void RemoveState();
		void ProcessStateChange();
		StateRef &GetActiveState();
		std::vector<StateRef> GetStates() { return _states; }
		
	private:
		StateManager();
		static StateManager *sm_instance;
		std::vector<StateRef> _states;
		StateRef _newState;

		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}
