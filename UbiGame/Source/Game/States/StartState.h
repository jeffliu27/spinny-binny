#pragma once
#include "GameEngine\Util\State.h"
#include "GameEngine\config.h"
#include "GameEngine/EntitySystem/Components/TextComponent.h"
#include "Game/GameEntities/TextEntity.h"
#include "Game/GameEntities/RectButton.h"

namespace Game
{
	class StartState : public GameEngine::State
	{
	public:
		StartState();
		~StartState();

		virtual void Init() override;
		virtual void Update(float dt) override;
		virtual void Dispose() override;

	};
}

