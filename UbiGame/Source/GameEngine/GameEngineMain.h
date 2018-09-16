#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "GameEngine\EntitySystem\Entity.h"
#include "GameEngine\EntitySystem\Components\RenderComponent.h"

namespace GameEngine
{
	class GameEngineMain
	{
	public:		
		~GameEngineMain();
				
		static GameEngineMain* GetInstance() { if (!sm_instance) sm_instance = new GameEngineMain(); return sm_instance; }
		//Returns time between update frames in seconds
		static float		   GetTimeDelta() { return GetInstance()->m_lastDT; }
		static float		   GetGameTime() { return sm_gameClock.getElapsedTime().asSeconds(); }

		sf::RenderWindow* GetRenderWindow() const { return m_renderWindow; }
		void Update();
		void SetRenderTarget(sf::RenderTarget* target) { m_renderTarget = target; }

		void OnInitialised();

	private:
		GameEngineMain();

		void CreateAndSetUpWindow();
		
		void UpdateWindowEvents();
		void RenderEntities();

		static GameEngineMain* sm_instance;
		static sf::Clock	   sm_deltaTimeClock;
		static sf::Clock	   sm_gameClock;

		sf::RenderTarget*   m_renderTarget;
		sf::RenderWindow*   m_renderWindow;						

		float				m_lastDT;

		bool m_windowInitialised;
	};
}
