#pragma once
#include "GameEngine\Util\State.h"

namespace Game
{
	class GameOverState : public GameEngine::State
	{
	public:
		GameOverState();
		~GameOverState();

		virtual void Init() override;
		virtual void Update(float dt) override;
		virtual void Dispose() override;
	};
}
