/////////////////////////////
// Class created by Jackson Wise, Spring 2023
// Created to add a timer to the players user interface
/////////////////////////////

#pragma once
#include "UIScreen.h"
class Timer : public UIScreen
{
public:
	Timer(class Game* game);
	~Timer();
	void CalcTime(float deltaTime);
	float GetTime() {return std::int64_t(mTimeSet);}

private:
	float mTimeSet;
};