#include "StateManager.h"

#include "GameEngine\GameEngineMain.h"

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

void StateManager::SwitchState(State* newState) {
	delete GameEngine::StateManager::GetInstance()->state;
	GameEngine::StateManager::GetInstance()
		->state = newState;
	GameEngine::GameEngineMain::GetInstance()->OnInitialised();
}

