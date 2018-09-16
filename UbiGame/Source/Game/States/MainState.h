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

		void InitGravity(sf::Vector2f center, double strength);
		void InitFriction(double friction) { friction = friction; }
		sf::Vector2f GravityAt(sf::Vector2f pos);
		float ApplyFriction(float vel);

	private:
		Game::GameBoard* m_gameBoard;

		sf::Vector2i gravityCenter;
		double gravityStrength;
		double friction;
	};
}

