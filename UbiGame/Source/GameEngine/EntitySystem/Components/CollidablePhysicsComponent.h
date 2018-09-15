#pragma once
#include "GameEngine\EntitySystem\Components\CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class CollidablePhysicsComponent : public CollidableComponent
	{
	public:
		CollidablePhysicsComponent();
		virtual ~CollidablePhysicsComponent();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;

		bool UsesGravity() const { return m_useGravity; }
		bool GetMass() const { return m_mass; }

		void SetGravityUsage(bool useGravity) { m_useGravity = useGravity; }
		void SetMass(double mass) { m_mass = mass; }

	private:
		bool m_useGravity = true;
		double m_mass = 1.0;

	};
}

