#pragma once
// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include "UIScreen.h"
#include "FollowActor.h"
class Speedometer : public UIScreen
{
public:
	Speedometer(class Game* game);
	~Speedometer();

	
	void CalcSpeed(FollowActor* car);

private:
	//std::unordered_map<std::string, std::string> mText;

};