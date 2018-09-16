#include "Source/GameEngine/GameEngineMain.h"
#include "Source/GameEngine/Util/StateManager.h"
#include "Source/Game/States/MainState.h"

#include <memory>

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();
	GameEngine::StateManager::GetInstance()
		->AddState(GameEngine::StateRef(new Game::MainState()));
	while (mainEngine->GetRenderWindow()->isOpen())
	{				
		mainEngine->Update();
	}

	delete mainEngine;
	return 0;
}