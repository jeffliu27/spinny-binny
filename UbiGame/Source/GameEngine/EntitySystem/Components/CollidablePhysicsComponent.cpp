#include "CollidablePhysicsComponent.h"

#include "Game\States\MainState.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine\Util\StateManager.h"
#include "GameEngine/EntitySystem/Entity.h"

#include <vector>

using namespace GameEngine;

CollidablePhysicsComponent::CollidablePhysicsComponent()
	: m_vel(sf::Vector2f(0.0, 0.0))
{

}


CollidablePhysicsComponent::~CollidablePhysicsComponent()
{

}


void CollidablePhysicsComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void CollidablePhysicsComponent::OnRemoveFromWorld()
{
	__super::OnAddToWorld();
}


void CollidablePhysicsComponent::Update()
{
	if (m_useGravity) {
		sf::Vector2f grav = GameEngine::GameEngineMain::GetInstance()
			->GravityAt(GetEntity()->GetPos());
		// update velocity based on gravity and mass
		// m_vel.x = grav.x / m_mass;
		// m_vel.y = grav.y / m_mass;
		m_vel.x += grav.x / m_mass;
		m_vel.y += grav.y / m_mass;
		// add friction (so it eventually slows down)
		m_vel.x += GameEngine::GameEngineMain::GetInstance()->ApplyFriction(m_vel.x);
		m_vel.y += GameEngine::GameEngineMain::GetInstance()->ApplyFriction(m_vel.y);
		GetEntity()->SetPos(sf::Vector2f(
			GetEntity()->GetPos().x + m_vel.x,
			GetEntity()->GetPos().y + m_vel.y
		));
	}
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	/*for (int a = 0; a < collidables.size(); ++a)
	{
		CollidableComponent* colComponent = collidables[a];
		if (colComponent == this)
			continue;

		AABBRect intersection;
		AABBRect myBox = GetWorldAABB();
		AABBRect colideBox = colComponent->GetWorldAABB();
		if (myBox.intersects(colideBox, intersection))
		{
			sf::Vector2f pos = GetEntity()->GetPos();
			if (intersection.width < intersection.height)
			{
				if (myBox.left < colideBox.left)
					pos.x -= intersection.width;
				else
					pos.x += intersection.width;
			}
			else
			{
				if (myBox.top < colideBox.top)
					pos.y -= intersection.height;
				else
					pos.y += intersection.height;
			}

			GetEntity()->SetPos(pos);
		}
	}*/
}