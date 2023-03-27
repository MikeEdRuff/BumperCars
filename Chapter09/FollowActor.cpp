// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

////////////////////
// Edited by Jackson Wise, Spring 2023
// Edited to fit the parameters of the game X-TREME BUMPER CARS
// Added drift mechanics, boost mechanics, and more realistic car physics
////////////////////

#include "FollowActor.h"
#include "MeshComponent.h"
#include "Game.h"
#include "Renderer.h"
#include "FollowCamera.h"
#include "MoveComponent.h"

FollowActor::FollowActor(Game* game)
	:Actor(game)
{
	mMeshComp = new MeshComponent(this);
	mMeshComp->SetMesh(game->GetRenderer()->GetMesh("Assets/playerCar.gpmesh"));
	SetPosition(Vector3(0.0f, 0.0f, -100.0f));

	mMoveComp = new MoveComponent(this);
	mCameraComp = new FollowCamera(this);
	mCameraComp->SnapToIdeal();
}

void FollowActor::ActorInput(const uint8_t* keys)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;

	const float maxSpeed = 1600.0f;
	const float maxBoost = 2400.0f;

	// wasd movement
	if (keys[SDL_SCANCODE_W])
	{
		if (mForwardSpeed < maxSpeed)
			mForwardSpeed += mAcceleration;

		//BOOOOOOST
		if (keys[SDL_SCANCODE_SPACE] && mForwardSpeed < maxBoost && mBoostCooldown <= 0.0f)
		{
			// JCW - If there is boost to use
			if (mBoostDuration > 0.0f)
			{
				mForwardSpeed += mAcceleration * 2;
				mBoostDuration -= 0.1f;
			}

			// JCW - Once the boost is used up
			else if (mBoostDuration <= 0.0f)
			{
				mBoostCooldown = 2.0f; // JCW - Time until next boost (2 seconds)
			}
		}
	}
	if (keys[SDL_SCANCODE_S])
	{
		if (mForwardSpeed > -maxSpeed/2)
			mForwardSpeed -= mAcceleration;
	}
	if (keys[SDL_SCANCODE_A] && mForwardSpeed != 0.0f)
	{
		angularSpeed -= Math::Pi;

		// JCW - Drift Mechanics
		if (keys[SDL_SCANCODE_LSHIFT])
			angularSpeed *= 1.5;
	}
	if (keys[SDL_SCANCODE_D] && mForwardSpeed != 0.0f)
	{
		angularSpeed += Math::Pi;

		// JCW - Drift Mechanics
		if (keys[SDL_SCANCODE_LSHIFT])
			angularSpeed *= 1.5;
	} 

	// JCW - Gradually slows down if nothing is being done
	else
	{
		if (mForwardSpeed > 0)
			mForwardSpeed -= mAcceleration/2;
	}

	mMoveComp->SetForwardSpeed(mForwardSpeed);
	mMoveComp->SetAngularSpeed(angularSpeed);

	// Adjust horizontal distance of camera based on speed
	if (!Math::NearZero(forwardSpeed))
	{
		mCameraComp->SetHorzDist(500.0f);
	}
	else
	{
		mCameraComp->SetHorzDist(350.0f);
	}
}

void FollowActor::UpdateActor(float deltaTime)
{
	// Jackson Wise
	if (mBoostDuration <= 6.0f)
		mBoostDuration += deltaTime; 
	mBoostCooldown -= deltaTime;
}

void FollowActor::SetVisible(bool visible)
{
	mMeshComp->SetVisible(visible);
}
