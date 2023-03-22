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

	void AiCarMovementPatrol();
	void AiCarMovementRun();

	void SetVisible(bool visible);
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCameraComp;
	class MeshComponent* mMeshComp;
	const float mAcceleration = 20.0f;
	float mForwardSpeed;
	int currentTarget = 0;
	int xTargets[5] = { 0, 1000, 1500, 0, -1000 };
	int yTargets[5] = { 0, 1000, 1500, 0, -1000 };

};
