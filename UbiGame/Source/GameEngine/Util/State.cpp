#include "State.h"

#include <assert.h>

using namespace GameEngine;

void State::AddEntity(Entity* entity)
{
	auto found = std::find(entities.begin(), entities.end(), entity);
	assert(found == entities.end()); //Drop an assert if we add duplicate;
	if (found == entities.end())
	{
		_entitiesToAdd.push_back(entity);
	}
}

void State::RemoveEntity(Entity* entity)
{
	auto found = std::find(entities.begin(), entities.end(), entity);

	if (found != entities.end())
	{
		_entitiesToRemove.push_back(entity);
		entity->OnRemoveFromWorld();
	}
}

void State::AddPendingEntities()
{
	for (int a = 0; a < _entitiesToAdd.size(); ++a)
	{
		entities.push_back(_entitiesToAdd[a]);
		_entitiesToAdd[a]->OnAddToWorld();
	}

	_entitiesToAdd.clear();
}

void State::RemovePendingEntities()
{
	for (int a = 0; a < _entitiesToRemove.size(); ++a)
	{
		Entity* entity = _entitiesToRemove[a];

		auto found = std::find(entities.begin(), entities.end(), entity);
		assert(found != entities.end());

		if (found != entities.end())
		{
			entities.erase(found);

			delete entity;
		}
	}
	_entitiesToRemove.clear();
}

void State::UpdateEntities()
{
	RemovePendingEntities();
	//Update que
	for each (auto entity in entities)
	{
		entity->Update();
	}
	AddPendingEntities();
}

