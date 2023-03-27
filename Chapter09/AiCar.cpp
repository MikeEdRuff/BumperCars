// Ai car cpp file
// Michael Ruff (MER)
// Spring 2023

#include "AiCar.h"
#include "MeshComponent.h"
#include "Game.h"
#include "Renderer.h"
#include "MoveComponent.h"
#include "CircleComponent.h"
AiCar::AiCar(Game* game)
	:Actor(game)
{
	mMeshComp = new MeshComponent(this);
	mMeshComp->SetMesh(game->GetRenderer()->GetMesh("Assets/aiCar.gpmesh"));
	SetPosition(Vector3(0,0,0));

	mCircle = new CircleComponent(this);	//carl Mcaninch
	mCircle->SetRadius(100.0f);

	mMoveComp = new MoveComponent(this);
}

void AiCar::AiCarMovement()
{
	mMoveComp->SetForwardSpeed(2000);
	mMoveComp->SetAngularSpeed(5);
	
}

void AiCar::Update() //Carl McAninch
{
	if (Intersect(*(GetGame()->GetPlayerCar().GetCircle()), *mCircle))
	{
		SetPosition(Vector3(1000000,100000,100000));
	}
}

// Sets the seed and spawn location of the car
void AiCar::AiSeedSet(int setSeed)
{
	seed = setSeed;
	SetPosition(spawn[seed]);
}

/*
void AiCar::ActorInput(const uint8_t* keys)
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
		if (mForwardSpeed > -maxSpeed / 2)
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

	// JCW - Gradually slows down if nothing is being done
	else
	{
		if (mForwardSpeed > 0)
			mForwardSpeed -= mAcceleration / 2;
	}

	mMoveComp->SetForwardSpeed(mForwardSpeed);
	mMoveComp->SetAngularSpeed(angularSpeed);

}
*/

void AiCar::SetVisible(bool visible)
{
	mMeshComp->SetVisible(visible);
}
