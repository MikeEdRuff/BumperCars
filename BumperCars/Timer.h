#pragma once
#include "UIScreen.h"
class Timer : public UIScreen
{
public:
	Timer(class Game* game);
	~Timer();
	void CalcTime(float deltaTime);

private:
	float mTimeSet;
};