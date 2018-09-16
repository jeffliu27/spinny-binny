#include "TextEntity.h"
#include <SFML/Graphics.hpp>

using namespace Game;

TextEntity::TextEntity()
{
	m_textComponent = static_cast<GameEngine::TextComponent*>(AddComponent<GameEngine::TextComponent>());
	
	m_textComponent->SetZLevel(5);
}

TextEntity::~TextEntity()
{

}

void TextEntity::OnAddToWorld()
{
	__super::OnAddToWorld();
}

void TextEntity::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}