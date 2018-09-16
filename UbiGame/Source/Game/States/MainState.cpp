#include "GameEngine\config.h"
#include "MainState.h"

using namespace Game;

MainState::MainState()
	: m_gameBoard(nullptr)
{
}


MainState::~MainState()
{
}

void MainState::Init()
{
	InitGravity(sf::Vector2f(0.5, 0.5), 0.01);  // 0.00001
	InitFriction(0.0001);
	m_gameBoard = new GameBoard();
}

void MainState::Update(float dt)
{
	if (m_gameBoard)
		m_gameBoard->Update();
}

void MainState::Dispose()
{

}

void MainState::InitGravity(sf::Vector2f center, double strength)
{
	gravityCenter.x = round(center.x * GameEngine::WINDOW_WIDTH);
	gravityCenter.y = round(center.y * GameEngine::WINDOW_HEIGHT);
	gravityStrength = strength;
}


sf::Vector2f MainState::GravityAt(sf::Vector2f pos)
{
	return sf::Vector2f(
		(gravityCenter.x - pos.x) * gravityStrength,
		(gravityCenter.y - pos.y) * gravityStrength
	);
}

float MainState::ApplyFriction(float vel)
{
	return vel > 0
		? vel - friction > 0
			? -friction
			: 0.0
		: vel + friction < 0
			? friction
			: 0.0;
}

