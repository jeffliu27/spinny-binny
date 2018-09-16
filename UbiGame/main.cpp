#include "Source/GameEngine/GameEngineMain.h"
#include "Source/GameEngine/Util/StateManager.h"
#include "Source/Game/States/MainState.h"

#include <memory>

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();
	GameEngine::GameEngineMain::GetInstance()->InitGravity(sf::Vector2f(0.5, 0.5), 0.00001);
	GameEngine::GameEngineMain::GetInstance()->InitFriction(0.001);
	GameEngine::State* mainState = new Game::MainState();
	GameEngine::StateManager::GetInstance()
		->state = mainState;
	while (mainEngine->GetRenderWindow()->isOpen())
	{				
		mainEngine->Update();
	}
	delete mainState;
	delete mainEngine;
	return 0;
}