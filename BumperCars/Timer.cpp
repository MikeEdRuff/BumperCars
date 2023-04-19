#include "Timer.h"
#include "Game.h"
#include "DialogBox.h"
#include <SDL/SDL.h>
#include <rapidjson/document.h>
#include <string>
#include "UIScreen.h"

Timer::Timer(Game* game)
	:UIScreen(game, 300.0f, 200.0f)
{

}

Timer::~Timer()
{
}

void Timer::CalcTime(float deltaTime)
{
	mTimeSet += deltaTime;
	int time = std::int64_t(mTimeSet);
	SetTitle(std::to_string(time) + "s");
}