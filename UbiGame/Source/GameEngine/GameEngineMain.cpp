#include "config.h"
#include "GameEngineMain.h"

#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include "Util/TextureManager.h"
#include "Util/AnimationManager.h"
#include "Util/CameraManager.h"
#include "Util/StateManager.h"

using namespace GameEngine;

//Nullptr init for singleton class
GameEngineMain* GameEngineMain::sm_instance = nullptr;
sf::Clock		GameEngineMain::sm_deltaTimeClock;
sf::Clock		GameEngineMain::sm_gameClock;

GameEngineMain::GameEngineMain()
	: m_renderTarget(nullptr)	
	, m_windowInitialised(false)
	, m_lastDT(0.f)
{
	CreateAndSetUpWindow();
	//Load predefined textures
	TextureManager::GetInstance()->LoadTextures();
	//Create predefined animation definition vector
	AnimationManager::GetInstance()->InitStaticGameAnimations();

	CameraManager::GetInstance()->GetCameraView().setCenter(sf::Vector2f(WINDOW_WIDTH / 2.f, WINDOW_HEIGHT / 2.f));
	CameraManager::GetInstance()->GetCameraView().setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
}


GameEngineMain::~GameEngineMain()
{
	StateManager::GetInstance()->GetActiveState()->Dispose();
	delete m_renderTarget;
}


void GameEngineMain::OnInitialised()
{
	StateManager::GetInstance()->GetActiveState()->Init();
	//Engine is initialised, this spot should be used for game object and clocks initialisation
	sm_deltaTimeClock.restart();
	sm_gameClock.restart();
	m_lastDT = 0.f;
}


void GameEngineMain::CreateAndSetUpWindow()
{
	m_renderWindow = new sf::RenderWindow(sf::VideoMode((unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT), "Spinny Binny");
	m_renderTarget = m_renderWindow;
}


void GameEngineMain::Update()
{		
	//First update will happen after init for the time being (we will add loading later)
	if (!m_windowInitialised)
	{
		m_windowInitialised = true;
		OnInitialised();
	}

	//for (auto const& state : StateManager::GetInstance()->GetStates())
	// 	state->RemovePendingEntities();
	StateManager::GetInstance()->GetActiveState()
		->RemovePendingEntities();

	UpdateWindowEvents();
	
	StateManager::GetInstance()->GetActiveState()
		->Update(0.0);

	//for (auto const& state : StateManager::GetInstance()->GetStates())
	//	state->UpdateEntities();
	StateManager::GetInstance()->GetActiveState()
		->UpdateEntities();
	RenderEntities();

	//for (auto const& state : StateManager::GetInstance()->GetStates())
	//	state->AddPendingEntities();
	StateManager::GetInstance()->GetActiveState()
		->AddPendingEntities();

	//We pool last delta and will pass it as GetTimeDelta - from game perspective it's more important that DT stays the same the whole frame, rather than be updated halfway through the frame
	m_lastDT = sm_deltaTimeClock.getElapsedTime().asSeconds();
	sm_deltaTimeClock.restart();
}


void GameEngineMain::UpdateWindowEvents()
{
	if (!m_renderWindow)
		return;

	sf::Event event;
	while (m_renderWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_renderWindow->close();
			m_renderTarget = nullptr;		
			break;
		}
	}
}


void GameEngineMain::RenderEntities()
{
	if (!m_renderTarget)
		return;

	//Here we use a windowRender target - it's more than enough for provided example, but in more complex versions this could end up flickering on the screen
	//If that is the case - one could try to implement doubleBuffer functionality, where the render target is a TEXTURE in memory and objects render there
	//And only at the last bit we render the prepared texture on the window.
	m_renderTarget->clear();

	//The VIEW is the way to control what renders in the window in a very convenient way - view does not modify the local coordinates, but rather than that it defines the rectangle that the window
	//Is supposed to render - by default our camera manager is not doing anything, as it was not needed in bird implementation, but it can be set to follow the player (by modifying the IsFollow enabled static return)
	//If that setting is on, PlayerCamera component will update the camera position to player position - making our camera center on player entity
	//With that test setting on, our bird implementation changes a bunch of rules, just so we can test it easilly
	m_renderTarget->setView(CameraManager::GetInstance()->GetCameraView());

	//Render que
	std::vector<RenderComponent*> renderers;
	//Every entity that has RenderComponent, or a component that extends RenderComponent - should end up in a render que
	for (auto const& state: StateManager::GetInstance()->GetStates())
	{
		for each (auto entity in state->entities)
		{
			if (RenderComponent* render = entity->GetComponent< RenderComponent >())
			{
				renderers.push_back(render);
			}
		}
	}

	// sort using a lambda expression
	// We sort entities according to their Z level, meaning that the ones with that value lower will be draw FIRST (background), and higher LAST (player)
	std::sort(renderers.begin(), renderers.end(), [](RenderComponent* a, RenderComponent* b) 
	{
		return a->GetZLevel() < b->GetZLevel();
	});	

	for each (auto renderer in renderers)
	{		
		renderer->Render(m_renderTarget);
	}

	if (m_renderWindow && m_renderWindow->isOpen())
	{
		m_renderWindow->display();
	}	
}

