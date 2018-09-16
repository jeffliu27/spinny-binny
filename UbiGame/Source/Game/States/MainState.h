#pragma once
#include "GameEngine\Util\State.h"
#include "Game\GameBoard.h"

namespace Game
{
	class MainState: public GameEngine::State
	{
	public:
		MainState();
		~MainState();

		void Init();
		void Update(float dt);
		void Dispose();

		bool IsGameOver() const { return m_gameBoard && m_gameBoard->IsGameOver(); }

	private:
		Game::GameBoard* m_gameBoard;

	};
}

