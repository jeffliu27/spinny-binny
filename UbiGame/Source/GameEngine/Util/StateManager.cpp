#include "StateManager.h"

using namespace GameEngine;

//Nullptr init for singleton class
StateManager* StateManager::sm_instance = nullptr;

StateManager::StateManager()
{
}


StateManager::~StateManager()
{
	delete sm_instance;
}

