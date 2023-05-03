/////////////////////////////
// Class created by Jackson Wise, Spring 2023
// Created to add a timer to the players user interface
/////////////////////////////

#include "Scoreboard.h"
#include "Game.h"
#include "DialogBox.h"
#include <SDL/SDL.h>
#include <rapidjson/document.h>
#include <string>
#include "UIScreen.h"

Scoreboard::Scoreboard(Game* game)
	:UIScreen(game, 0.0f, 200.0f)
{

}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::SetScore(int numTagged)
{
	SetTitle(std::to_string(numTagged)+"pts");
}