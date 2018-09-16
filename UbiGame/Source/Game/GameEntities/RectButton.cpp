#include "RectButton.h"
#include "GameEngine\EntitySystem\Components\MouseInputComponent.h"
#include <iostream>
using namespace Game;

RectButton::RectButton(int z)
{
	m_mouseComponent = static_cast<GameEngine::MouseInputComponent*>(AddComponent<GameEngine::MouseInputComponent>());
	m_textComponent = static_cast<GameEngine::TextComponent*>(AddComponent<GameEngine::TextComponent>());
	m_textComponent->SetZLevel(z);

	GetComponent<GameEngine::MouseInputComponent>()->AddCallback(GameEngine::ButtonType::NONE, wrap([&]()
	{
		if (PosInBounds(m_mouseComponent->pos)) {
			std::cout << "hover" << std::endl;
			m_textComponent->SetBackgroundColour(_hoverColour);
		}
		else
			m_textComponent->SetBackgroundColour(_colour);
	}));
	GetComponent<GameEngine::MouseInputComponent>()->AddCallback(GameEngine::ButtonType::LEFT, wrap([&]()
	{
		if (PosInBounds(m_mouseComponent->pos)) _onClick();
	}));
}


RectButton::~RectButton()
{
}

bool RectButton::PosInBounds(sf::Vector2i pos)
{
	return (GetPos().x + GetSize().x / 2.f > pos.x && GetPos().x - GetSize().x / 2.f < pos.x) &&
		(GetPos().y + GetSize().y / 2.f > pos.y && GetPos().y - GetSize().y / 2.f < pos.y);
}

void RectButton::OnAddToWorld()
{
	__super::OnAddToWorld();
	
}

void RectButton::OnRemoveFromWorld()
{
	__super::OnRemoveFromWorld();
}
