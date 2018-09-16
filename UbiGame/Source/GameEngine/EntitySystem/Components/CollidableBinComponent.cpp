#include "CollidableBinComponent.h"
#include "CollidablePhysicsComponent.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CollisionManager.h"
#include "GameEngine/EntitySystem/Entity.h"
#include "Game/GameEntities/ProjectileEntity.h"
#include "GameEngine/Util/State.h"
#include "GameEngine/Util/StateManager.h"

#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace GameEngine;

double CollidableBinComponent::getRadius()
{
	return m_radius;
}
double CollidableBinComponent::getAngle()
{
	return m_angle;
}

CollidableBinComponent::CollidableBinComponent()
{

}


CollidableBinComponent::~CollidableBinComponent()
{

}


void CollidableBinComponent::OnAddToWorld()
{
	__super::OnAddToWorld();
}


void CollidableBinComponent::OnRemoveFromWorld()
{
	__super::OnAddToWorld();
}


void CollidableBinComponent::Update()
{
	//For the time being just a simple intersection check that moves the entity out of all potential intersect boxes
	std::vector<CollidableComponent*>& collidables = CollisionManager::GetInstance()->GetCollidables();

	double vectorRotation = ((int) GetEntity()->GetRot() )% 360;
	std::cout << vectorRotation << std::endl;
	double Threshold = 45.f;

	double valid_recycle_start = ((int)(vectorRotation + Threshold)) % 360;
	double valid_recycle_end = ((int)(vectorRotation)) % 360;

	double valid_garbage_start = ((int)(vectorRotation + 180)) % 360;
	double valid_garbage_end = ((int)(vectorRotation + 180 + Threshold)) % 360;

	int count = 0;
	for (int i =0; i< collidables.size();
		i++)
	{	

		
		CollidableComponent* colComponent = collidables[i];
		if (colComponent == NULL) {
			std::wcout << "null" << std::endl;
		}
		else if (colComponent == this) {
			//it++;
		}
		else if (colComponent!= NULL && colComponent->GetEntity() != NULL) {




			AABBRect intersection;
			//AABBRect myBox = GetWorldAABB();

			/*T left;   ///< Left coordinate of the rectangle
			T top;    ///< Top coordinate of the rectangle
			T width;  ///< Width of the rectangle
			T height;*/

			AABBRect colideBox = colComponent->GetWorldAABB();

			//assume center
			sf::Vector2f pos_collidable = colComponent->GetEntity()->GetPos();
			sf::Vector2f bin_collidable = GetEntity()->GetPos();

			sf::Vector2f diff_vector = pos_collidable - bin_collidable;
			double distance_squared = (diff_vector.x)*(diff_vector.x) + (diff_vector.y)*(diff_vector.y);
			double radius_squared = m_radius * m_radius;
			//std::cout << "hello world" << std::endl;

			if (distance_squared <= radius_squared) {
				//collision
				//std::cout << "hello world" << std::endl;
				//colComponent->SetVel(-(colComponent->GetVel()));
				//TODO: Access center of trash
				//Find the principal angle between trash and initial arm
				double principal = atan(diff_vector.y / diff_vector.x) * 57.2958;

				//Check if angle is within bin range
				double real_angle = 0;
				if (diff_vector.x>0) {
					if (diff_vector.y>0) {
						real_angle = principal;
					}
					else {
						real_angle = 360 - principal;

					}
				}
				else {
					if (diff_vector.y>0) {
						real_angle = 180 - principal;
					}
					else {
						real_angle = 180 + principal;

					}

				}
				if (real_angle > valid_recycle_start && real_angle < valid_recycle_end || real_angle > valid_garbage_start && real_angle < valid_garbage_end) {
					std::cout << "fusdkfsdlfk" << std::endl;
					CollisionManager::GetInstance()->UnRegisterCollidable(colComponent);
					//colComponent->GetEntity()->shouldDelete = true;
					Entity* ent_ptr = colComponent->GetEntity();

					Game::ProjectileEntity* projectile_entity = dynamic_cast<Game::ProjectileEntity*> (ent_ptr);
					//If it is not recyclable

					GameEngine::StateManager::GetInstance()->state
						->RemoveEntity(ent_ptr);
					//it = collidables.erase(it);
					//State::RemoveEntity(ent_ptr);
					//it++;
				}
				else {
					//it++;
				}

			}
			else {
				//it++;
			}
		}

		//count++;
		//std::cout << count << ' ';
		
	}

	//std::cout<<std::endl;
}
