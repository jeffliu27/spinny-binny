#pragma once
#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\MouseInputComponent.h"
#include "GameEngine\EntitySystem\Components\TextComponent.h"

namespace Game
{
	typedef void(*OnClick)();

	class RectButton : public GameEngine::Entity
	{
	public:
		RectButton(int z = -1);
		~RectButton();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		
		bool PosInBounds(sf::Vector2i pos);

		void SetOnClick(const OnClick onClick) { _onClick = onClick; }
		void SetText(const sf::String str) { m_textComponent->SetText(str); }
		void SetTextColour(const sf::Color colour) { m_textComponent->SetTextColour(colour); }
		void SetColour(const sf::Color colour) { _colour = colour; m_textComponent->SetBackgroundColour(colour); }
		void SetHoverColour(const sf::Color colour) { _hoverColour = colour; }

	private:
		GameEngine::MouseInputComponent* m_mouseComponent;
		GameEngine::TextComponent* m_textComponent;

		sf::Color _colour;
		sf::Color _hoverColour;
		OnClick _onClick;
	};
}

