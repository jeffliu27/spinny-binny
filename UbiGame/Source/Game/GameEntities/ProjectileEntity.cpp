#include "ProjectileEntity.h"

#include "GameEngine/EntitySystem/Components/CollidableComponent.h"

#include <SFML/Graphics.hpp>

using namespace Game;

Game::ProjectileEntity::ProjectileEntity()
{
	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetTexture(GameEngine::eTexture::Apple);
	m_renderComponent->SetZLevel(2);
	

	m_physicsComponent = static_cast<GameEngine::CollidablePhysicsComponent*>(AddComponent<GameEngine::CollidablePhysicsComponent>());
	m_physicsComponent->SetMass(12.0);
}

Game::ProjectileEntity::ProjectileEntity(int trashTypeIndex)
{
	trashTypeID = trashTypeIndex;
	isRecyclable = (trashTypeID == 5 || trashTypeID == 7 || trashTypeID == 9 || trashTypeID == 12);

	m_renderComponent = static_cast<GameEngine::SpriteRenderComponent*>(AddComponent<GameEngine::SpriteRenderComponent>());
	m_renderComponent->SetFillColor(sf::Color::Red);
	m_renderComponent->SetZLevel(2);

	m_renderComponent->SetTexture(GameEngine::eTexture::type(trashTypeIndex));

	m_physicsComponent = static_cast<GameEngine::CollidablePhysicsComponent*>(AddComponent<GameEngine::CollidablePhysicsComponent>());
	m_physicsComponent->SetMass(12.0);
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
