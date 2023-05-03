/////////////////////////////
// Class created by Jackson Wise, Spring 2023
// Created to add a scoreboard to the players user interface
/////////////////////////////

#pragma once
#include "UIScreen.h"
class Scoreboard : public UIScreen
{
public:
	Scoreboard(class Game* game);
	~Scoreboard();
	void Scoreboard::SetScore(int numTagged);
private:
};