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
	float mOffset = 2.3f; // Jackson Wise
	float mForwardSpeed;
	float mDeathTimer = 0.5f;
	class Mesh* mExplosion;

	// seed decides spawn location and movement of the car
	int seed;
	Vector3 spawn[5] = { Vector3(1000 / mOffset, 1100 / mOffset, -100), Vector3(10000 / mOffset,2000 / mOffset,-100), Vector3(4000 / mOffset,9000 / mOffset,-100), 
						Vector3(5000 / mOffset,4000 / mOffset,-100), Vector3(3000 / mOffset,9000 / mOffset,-100) };

	float targetX[5][4] = { {4000 / mOffset,8000 / mOffset,5000 / mOffset,1000 / mOffset},
							{5000 / mOffset,6000 / mOffset,5000 / mOffset,10000 / mOffset},
							{500 / mOffset,1000 / mOffset,2500 / mOffset,4000 / mOffset},
							{3000 / mOffset,3000 / mOffset,5000 / mOffset,5000 / mOffset} ,
							{4000 / mOffset,100 / mOffset,1500 / mOffset,3000 / mOffset} };

	float targetY[5][4] = { {300 / mOffset,9000 / mOffset,2000 / mOffset,1100 / mOffset},
							{8000 / mOffset,4000 / mOffset,2000 / mOffset,2000 / mOffset},
							{9000 / mOffset,500 / mOffset,1000 / mOffset,9000 / mOffset},
							{4000 / mOffset,500 / mOffset,1000 / mOffset,4000 / mOffset},
							{7000 / mOffset,4000 / mOffset,3000 / mOffset,9000 / mOffset} };

	Vector3 UnitZ = Vector3(0.0f, 0.0f, 1.0f);

	int currentTarget = 0;

	class CircleComponent* mCircle;	// Carl McANinch
	bool firstHit = true; // Jackson Wise - Checking if the car has been hit
};
