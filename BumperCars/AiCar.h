// Ai car h file
// Michael Ruff 
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
	void Update(float delataTime);
	void SetVisible(bool visible);
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCameraComp;
	class MeshComponent* mMeshComp;
	const float mAcceleration = 20.0f;
	const float offset = 2.0f;
	float mForwardSpeed;
	float mDeathTimer = 0.5f;
	class Mesh* mExplosion;

	// seed decides spawn location and movement of the car
	int seed;
	Vector3 spawn[3] = { Vector3(1000.0f, 1000.0f, -100.0f), Vector3(10000,2000,-100), Vector3(4000,9000,-100) };
	float targetX[3][10] = { {1000/offset,2000 / offset,8000 / offset,7000 / offset,4500 / offset,4000 / offset,3000 / offset,2000 / offset,2000 / offset,1000 / offset},
						   {5000 / offset,4000 / offset,6000 / offset,5000 / offset,9000 / offset,3000 / offset,8000 / offset,9000 / offset,4000 / offset,10000 / offset},
						   {500 / offset,1000 / offset,2000 / offset,2500 / offset,1000 / offset,2000 / offset,1000 / offset,1000 / offset,1000 / offset,4000 / offset} };

	float targetY[3][10] = { {8000 / offset,10000 / offset,9000 / offset,2000 / offset,2000 / offset,1000 / offset,1500 / offset,2000 / offset,500 / offset,1000 / offset},
						   {8000 / offset,5000 / offset,4000 / offset,1000 / offset,500 / offset,8000 / offset,9000 / offset,7500 / offset,5000 / offset,2000 / offset},
						   {8000 / offset,1000 / offset,500 / offset,2000 / offset,500 / offset,1000 / offset,1000 / offset,1000 / offset,1000 / offset,9000 / offset} };

	Vector3 UnitZ = Vector3(0.0f, 0.0f, 1.0f);

	int currentTarget = 0;

	class CircleComponent* mCircle;	// Carl McANinch
	bool firstHit = true; // Jackson Wise - Checking if the car has been hit
};
