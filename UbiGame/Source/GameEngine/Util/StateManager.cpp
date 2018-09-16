#include "StateManager.h"


using namespace GameEngine;

StateManager::StateManager()
{
}


StateManager::~StateManager()
{
}

void StateManager::AddState(StateRef newState, bool isReplacing)
{
	_isAdding = true;
	_isReplacing = isReplacing;
	_newState = std::move(newState);
}

void StateManager::RemoveState()
{
	_isRemoving = true;
}

void StateManager::ProcessStateChange()
{
	if (_isRemoving && !_states.empty())
	{
		_states.pop_back();
		// if (!_states.empty()) _states.top()->resume();
		_isRemoving = false;
	}
	if (_isAdding)
	{
		if (!_states.empty())
		{
			if (_isReplacing) _states.pop_back();
			// else _states.top()->pause();
		}
		_states.push_back(std::move(_newState));
		_states.back()->Init();
		_isAdding = false;
	}
}

StateRef &StateManager::GetActiveState()
{
	return _states.back();
}
