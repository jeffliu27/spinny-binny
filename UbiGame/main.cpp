#include "Source/GameEngine/GameEngineMain.h"
#include "Source/GameEngine/Util/StateManager.h"
#include "Source/Game/States/StartState.h"

#include <memory>

int main()
{
	GameEngine::GameEngineMain* mainEngine = GameEngine::GameEngineMain::GetInstance();
	GameEngine::GameEngineMain::GetInstance()->InitGravity(sf::Vector2f(0.5, 0.5), 0.000001);
	GameEngine::GameEngineMain::GetInstance()->InitFriction(0.001);
	GameEngine::State* mainState = new Game::StartState();
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