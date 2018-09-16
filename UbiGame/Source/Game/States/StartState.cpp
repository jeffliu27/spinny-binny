#include "StartState.h"
#include "GameEngine\config.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"
#include "GameEngine/Util/StateManager.h"
#include "Game/States/MainState.h"
#include "Game/GameEntities/TextEntity.h"
#include "Game/GameEntities/RectButton.h"
#include <iostream>

using namespace Game;

StartState::StartState()
{
}


StartState::~StartState()
{
}

void StartState::Init()
{
	TextEntity* gameOver = new TextEntity();
	gameOver->SetPos(sf::Vector2f(GameEngine::WINDOW_WIDTH / 2.f, GameEngine::WINDOW_HEIGHT / 2.f));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetTextSize(28);
	gameOver->GetComponent<GameEngine::TextComponent>()->SetText("WELCOME TO SPINNY BINNY!");
	gameOver->GetComponent<GameEngine::TextComponent>()->SetTextColour(sf::Color(50, 150, 50, 255));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetBackgroundColour(sf::Color(200, 0, 0, 255));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetBackgroundSize(sf::Vector2f(GameEngine::WINDOW_WIDTH, GameEngine::WINDOW_HEIGHT));
	gameOver->GetComponent<GameEngine::TextComponent>()->RecalcOrigin();

	RectButton* restartBtn = new RectButton();
	restartBtn->SetPos(sf::Vector2f(GameEngine::WINDOW_WIDTH / 2.f, GameEngine::WINDOW_HEIGHT * 3.f / 4.f));
	restartBtn->SetSize(sf::Vector2f(200.f, 100.f));
	restartBtn->SetOnClick([]()
	{
		std::cout << "GOING TO MAIN" << std::endl;
		GameEngine::StateManager::GetInstance()->SwitchState(new Game::MainState());
	});
	restartBtn->SetText("PLAY NOW");
	restartBtn->SetTextColour(sf::Color(50, 200, 20, 255));
	restartBtn->SetColour(sf::Color(0, 0, 0, 255));
	restartBtn->SetHoverColour(sf::Color(200, 200, 200, 255));

	entities.push_back(gameOver);
	entities.push_back(restartBtn);
}

void StartState::Update(float dt)
{

}

void StartState::Dispose()
{

}

