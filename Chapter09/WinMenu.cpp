/////////////////////////////
// Class created by Jackson Wise, Spring 2023
// Created to add a screen when the player wins the game
/////////////////////////////

#include "WinMenu.h"
#include "Game.h"
#include "DialogBox.h"
#include <SDL/SDL.h>

WinMenu::WinMenu(Game* game)
	:UIScreen(game)
{
	mGame->SetState(Game::EWin);
	SetRelativeMouseMode(false);
	SetTitle("WinTitle");
	AddButton("EndGame", [this]() {
		Close();
		});
}

WinMenu::~WinMenu()
{
	SetRelativeMouseMode(true);
	mGame->SetState(Game::EGameplay);
}

void WinMenu::HandleKeyPress(int key)
{
	UIScreen::HandleKeyPress(key);

	if (key == SDLK_ESCAPE)
	{
		mGame->SetState(Game::EQuit);
	}
}