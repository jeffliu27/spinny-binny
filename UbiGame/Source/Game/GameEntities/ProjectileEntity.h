#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\SpriteRenderComponent.h"
#include "GameEngine\EntitySystem\Components\CollidablePhysicsComponent.h"

namespace Game
{

	class ProjectileEntity : public GameEngine::Entity
	{
	public:
		ProjectileEntity();
		~ProjectileEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		
		double mass;
	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::CollidablePhysicsComponent* m_physicsComponent;
	};

}