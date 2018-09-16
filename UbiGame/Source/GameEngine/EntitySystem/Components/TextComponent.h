#pragma once
#include <SFML/Graphics.hpp>
#include "GameEngine\EntitySystem\Components\RenderComponent.h"
#include "GameEngine\GameEngineMain.h"

namespace GameEngine
{
	class TextComponent : public RenderComponent
	{
	public:
		TextComponent();
		virtual ~TextComponent();
	
		virtual void Update() override;
		virtual void Render(sf::RenderTarget* target) override;
		virtual void OnAddToWorld() override;

		void SetText(const sf::String textString) { m_text.setString(textString); }
		void SetTextSize(unsigned int size) { m_text.setCharacterSize(size); }
		void SetTextColour(const sf::Color colour) { m_text.setFillColor(colour); }

		void SetTextPosition(sf::Vector2f vect) { m_textPos = vect; }
		void SetTextPosition(float xIdx, float yIdx) { m_textPos = sf::Vector2f(xIdx, yIdx); }
		void SetTextBackgroundColour(const sf::Color colour) { m_rectangle.setFillColor(colour); }
		void UpdateTextParams();

	private:
		sf::Font m_font;
		sf::Text m_text;
		sf::Vector2f m_textPos;
		sf::RectangleShape m_rectangle;
	};
}