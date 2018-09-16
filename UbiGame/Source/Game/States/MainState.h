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

		virtual void Init() override;
		virtual void Update(float dt) override;
		virtual void Dispose() override;

		bool IsGameOver() const { return m_gameBoard && m_gameBoard->IsGameOver(); }

	private:
		Game::GameBoard* m_gameBoard;

	};
}

