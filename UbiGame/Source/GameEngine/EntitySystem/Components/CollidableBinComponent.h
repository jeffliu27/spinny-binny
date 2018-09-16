#pragma once

#include "GameEngine\EntitySystem\Components\CollidableComponent.h"

namespace GameEngine
{
	//This one allows for movement and obstacle detection, 
	class CollidableBinComponent : public CollidableComponent
	{
	public:
		CollidableBinComponent();
		virtual ~CollidableBinComponent();
		double getRadius();
		double getAngle();
		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

		virtual void Update() override;
		

	private:
		bool m_useGravity = true;
		double m_mass = 5.0;
		double m_radius = 200.f;
		double m_angle = 90.f;


	};
}

