// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

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
	mMeshComp->SetMesh(game->GetRenderer()->GetMesh("Assets/RacingCar.gpmesh"));
	SetPosition(Vector3(0.0f, 0.0f, -100.0f));

	mMoveComp = new MoveComponent(this);
	mCameraComp = new FollowCamera(this);
	mCameraComp->SnapToIdeal();
}

void FollowActor::ActorInput(const uint8_t* keys)
{
	float forwardSpeed = 0.0f;
	float angularSpeed = 0.0f;

	float maxSpeed = 1600.0f;

	// wasd movement
	if (keys[SDL_SCANCODE_W])
	{
		if (mForwardSpeed < maxSpeed)
			mForwardSpeed += mAcceleration;
	}
	if (keys[SDL_SCANCODE_S])
	{
		if (mForwardSpeed > -maxSpeed/2)
			mForwardSpeed -= mAcceleration;
	}
	if (keys[SDL_SCANCODE_A])
	{
		angularSpeed -= Math::Pi;
		if (keys[SDL_SCANCODE_LSHIFT])
			angularSpeed *= 1.5;
	}
	if (keys[SDL_SCANCODE_D])
	{
		angularSpeed += Math::Pi;
		if (keys[SDL_SCANCODE_LSHIFT])
			angularSpeed *= 1.5;
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

void FollowActor::SetVisible(bool visible)
{
	mMeshComp->SetVisible(visible);
}
