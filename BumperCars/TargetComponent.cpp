// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

//#include "BoxComponent.h"
#include "Actor.h"
#include "Game.h"
//#include "PhysWorld.h"
#include "TargetComponent.h"
#include "Math.h"
#include "Game.h"
#include "Radar.h" //Will Briggs (was #include "HUD.h")

TargetComponent::TargetComponent(Actor* owner)
	:Component(owner)
{
	mOwner->GetGame()->GetRadar()->AddTargetComponent(this); //Will Briggs
}

TargetComponent::~TargetComponent()
{
	mOwner->GetGame()->GetRadar()->RemoveTargetComponent(this); //Will Briggs
}
