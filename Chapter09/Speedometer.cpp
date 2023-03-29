// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#include "Speedometer.h"
#include "Game.h"
#include "DialogBox.h"
#include <SDL/SDL.h>
#include <rapidjson/document.h>
#include <string>
#include "UIScreen.h"
Speedometer::Speedometer(Game* game)
	:UIScreen(game, 300.0f, 0.0f)
{

	

}



Speedometer::~Speedometer()
{
}


void Speedometer::CalcSpeed(FollowActor* car)
{
	int speed1 = std::int64_t(car->getForwardSpeed() / 26.5);
	SetTitle(std::to_string(speed1));

	
}
