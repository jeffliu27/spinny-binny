#pragma once
#include "GameEngine\EntitySystem\Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>

namespace Game
{
	//Used for storing and controling all game related entities
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		//Temp - for nice architecture this should be within some sort of IUpdatable interface that GameEngine handles (so that not only entities can be updated)
		void Update();
		void UpdateProjectiles(float dt);
		void UpdatePlayerDying();
		void SpawnNewRandomProjectiles();
		void SpawnNewRandomTrash();
		void SpawnNewProjectile(const sf::Vector2f& pos, const sf::Vector2f& size);

		bool IsGameOver() const { return m_isGameOver; }		

	protected:

		void CreateBackGround();
		void UpdateBackGround();

		PlayerEntity* m_player;
		GameEngine::Entity* m_backGround;

		class TextEntity* m_text;

		std::vector<GameEngine::Entity*> m_projectiles;
		float m_lastProjectileSpawnTimer;
		bool  m_isGameOver;
	};
}

