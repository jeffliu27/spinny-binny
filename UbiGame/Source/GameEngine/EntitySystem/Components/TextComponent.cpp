#include "TextComponent.h"

using namespace GameEngine;

TextComponent::TextComponent()
	: m_font(sf::Font())
	, m_text(sf::Text())
	, m_textPos(sf::Vector2f(0,0))
	, m_rectangle(sf::RectangleShape(sf::Vector2f(0,0)))
{
	m_font.loadFromFile("RobotoMono-Regular.ttf");
	m_text.setFont(m_font);
	m_text.setString("bruh");
	m_text.setFillColor(sf::Color());
	m_rectangle.setSize(sf::Vector2f(800, 800));
	m_rectangle.setFillColor(sf::Color(200, 100, 150, 255));
	
}

TextComponent::~TextComponent()
{

}

void TextComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
	UpdateTextParams();
}

void TextComponent::UpdateTextParams()
{

		return;
	
}

void TextComponent::Update()
{
	
}


void TextComponent::Render(sf::RenderTarget* target)
{
	__super::Render(target);

	if (!target)
	{
		return;
	}

	//After the values are set, render itself is pretty simple
	m_text.setPosition(GetEntity()->GetPos());
	m_text.setRotation(GetEntity()->GetRot());

	target->draw(m_rectangle);
	target->draw(m_text);
}
