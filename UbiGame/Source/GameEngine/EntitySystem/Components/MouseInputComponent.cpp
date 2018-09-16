#include "MouseInputComponent.h"
#include <iostream>
using namespace GameEngine;

MouseInputComponent::MouseInputComponent()
{
}


MouseInputComponent::~MouseInputComponent()
{
}


void MouseInputComponent::OnAddToWorld()
{

}

void MouseInputComponent::Update()
{
	__super::Update();

	pos = sf::Mouse::getPosition();
	_leftPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	_rightPressed = sf::Mouse::isButtonPressed(sf::Mouse::Right);
	_middlePressed = sf::Mouse::isButtonPressed(sf::Mouse::Middle);

	for (auto it = _callbacks.begin(); it != _callbacks.end(); ++it)
	{
		std::cout << pos.x << std::endl;
		switch (it->first)
		{
		case NONE:
			it->second();
			break;
		case LEFT:
			if (_leftPressed) it->second();
			break;
		case MIDDLE:
			if (_middlePressed) it->second();
			break;
		case RIGHT:
			if (_rightPressed) it->second();
			break;
		}
	}
}
