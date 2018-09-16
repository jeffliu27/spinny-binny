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
	m_gameBoard = new GameBoard();
}

void MainState::Update(float dt)
{
	if (m_gameBoard)
		m_gameBoard->Update();
}

void MainState::Dispose()
{
	delete m_gameBoard;
}

