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

	void SetVisible(bool visible);
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCameraComp;
	class MeshComponent* mMeshComp;
	const float mAcceleration = 20.0f;
	float mForwardSpeed;

	// seed decides spawn location and movement of the car
	int seed;
	Vector3 spawn[3] = { Vector3(1000.0f, 1000.0f, -100.0f), Vector3(2000,2000,-100), Vector3(3000,3000,-100) };

};
