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
		ProjectileEntity(int trashTypeIndex);
		~ProjectileEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		
		double mass;
		bool isRecyclable;
		int trashTypeID;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::CollidablePhysicsComponent* m_physicsComponent;
	};

}
