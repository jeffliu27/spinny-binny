#pragma once
#include "GameEngine\EntitySystem\Component.h"
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <map>

#include <iostream>


template <class T>
auto wrap(T t) {
	static T fn = t;
	return [] { fn(); };
}


namespace GameEngine
{
	enum ButtonType {
		NONE,
		LEFT,
		MIDDLE,
		RIGHT
	};

	typedef void(*MouseCallback)();

	class MouseInputComponent : public GameEngine::Component
	{
	public:
		MouseInputComponent();
		~MouseInputComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		void AddCallback(ButtonType on, MouseCallback callback) { std::cout << "TEST" << std::endl; _callbacks.insert(std::pair<ButtonType, MouseCallback>(on, callback)); }

		sf::Vector2i pos;

	private:
		std::map<ButtonType, MouseCallback> _callbacks;
		bool _leftPressed;
		bool _rightPressed;
		bool _middlePressed;
	};
}

