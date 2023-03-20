// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "Actor.h"

class FollowActor : public Actor
{
public:
	FollowActor(class Game* game);

	void ActorInput(const uint8_t* keys) override;

	void UpdateActor(float deltaTime);

	void SetVisible(bool visible);
private:
	class MoveComponent* mMoveComp;
	class FollowCamera* mCameraComp;
	class MeshComponent* mMeshComp;
	const float mAcceleration = 20.0f;
	float mForwardSpeed;
	float mBoostCooldown; // Cooldown to next boost
	float mBoostDuration; // Duration of boost
};
