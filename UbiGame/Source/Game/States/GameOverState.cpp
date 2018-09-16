#include "GameOverState.h"
#include "GameEngine\config.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"
#include "Game/GameEntities/TextEntity.h"
#include "Game/GameEntities/RectButton.h"

using namespace Game;

GameOverState::GameOverState()
{
}


GameOverState::~GameOverState()
{
}


void GameOverState::Init()
{
	TextEntity* gameOver = new TextEntity();
	gameOver->SetPos(sf::Vector2f(GameEngine::WINDOW_WIDTH / 2.f, GameEngine::WINDOW_HEIGHT / 2.f));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetTextSize(28);
	gameOver->GetComponent<GameEngine::TextComponent>()->SetText("GAME OVER");
	gameOver->GetComponent<GameEngine::TextComponent>()->SetTextColour(sf::Color(50, 150, 50, 255));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetBackgroundColour(sf::Color(200, 0, 0, 255));
	gameOver->GetComponent<GameEngine::TextComponent>()->SetBackgroundSize(sf::Vector2f(GameEngine::WINDOW_WIDTH, GameEngine::WINDOW_HEIGHT));
	gameOver->GetComponent<GameEngine::TextComponent>()->RecalcOrigin();
	
	/*RectButton* restartBtn = new RectButton();
	restartBtn->SetOnClick([] () {});
	restartBtn->SetText("RESTART");
	restartBtn->SetTextColour(sf::Color(50, 200, 20, 255));
	restartBtn->SetColour(sf::Color(0, 0, 0, 255));
	restartBtn->SetHoverColour(sf::Color(200, 200, 200, 255));
	*/
	entities.push_back(gameOver);
	//entities.push_back(restartBtn);
}

void GameOverState::Update(float dt)
{

}

void GameOverState::Dispose()
{
	for (auto entity : entities) {
		RemoveEntity(entity);
	}
}
