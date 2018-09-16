#pragma once

#include "GameEngine\EntitySystem\Entity.h"
#include <vector>

namespace GameEngine
{
	class State
	{
	public:
		virtual void Init() = 0;
		virtual void Update(float dt) = 0;
		virtual void Dispose() = 0;
		//virtual void pause() = 0;
		//virtual void resume() = 0;

		void AddEntity(Entity* entity);
		void RemoveEntity(Entity* entity);
		void UpdateEntities();
		void AddPendingEntities();
		void RemovePendingEntities();

		std::vector<Entity*> entities;

	private:
		std::vector<Entity*> _entitiesToAdd;
		std::vector<Entity*> _entitiesToRemove;
	};
}
