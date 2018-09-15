#include "ProjectileEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

Game::ProjectileEntity::ProjectileEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetTexture(GameEngine::eTexture::Tileset);
	m_renderComponent->SetZLevel(2);
	

	m_physicsComponent = static_cast<GameEngine::CollidablePhysicsComponent*>(AddComponent<GameEngine::CollidablePhysicsComponent>());
	m_physicsComponent->SetMass(0.05);
}

ProjectileEntity::~ProjectileEntity()
{
}

void ProjectileEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void ProjectileEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
