// Ai car h file
// Michael Ruff (MER)
// Spring 2023

#pragma once
#include "Actor.h"

class AiCar : public Actor
{
public:
	AiCar(class Game* game);

	//void ActorInput(const uint8_t* keys) override;

	void AiCarMovement();

	void AiSeedSet(int setSeed);
	void Update();
	void SetVisible(bool visible);
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCameraComp;
	class MeshComponent* mMeshComp;
	const float mAcceleration = 20.0f;
	float mForwardSpeed;


	// seed decides spawn location and movement of the car
	int seed;
	Vector3 spawn[3] = { Vector3(1000.0f, 1000.0f, -100.0f), Vector3(10000,2000,-100), Vector3(4000,9000,-100) };
	float targetX[3][10] = { {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000},
						   {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000},
						   {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000} };

	float targetY[3][10] = { {10000,9000,8000,7000,6000,5000,4000,3000,2000,1000},
						   {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000},
						   {1000,2000,3000,4000,5000,6000,7000,8000,9000,1000} };

	Vector3 UnitZ = Vector3(0.0f, 0.0f, 1.0f);

	int currentTarget = 0;

	class CircleComponent* mCircle;	// Carl McANinch
};
