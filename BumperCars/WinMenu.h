/////////////////////////////
// Class created by Jackson Wise, Spring 2023
// Created to add a screen when the player wins the game
/////////////////////////////

#pragma once
#include "UIScreen.h"

class WinMenu : public UIScreen
{
public:
	WinMenu(class Game* game);
	~WinMenu();

	void HandleKeyPress(int key) override;

	class Texture* mLeaderboardTitle = nullptr;
	std::vector<class Texture*> mScoreTextures; //for printing the top 5 scores

	Vector2 mLeaderboardTitlePos;               //where does the Leaderboard title go?
	Vector2 mScorePos;                          //where does the first score go?

	//WinMenu now needs to override UIScreen's virtual function Draw:

	void WinMenu::Draw(Shader * shader)
	{
		UIScreen::Draw(shader);
		//now draw the leaderboard, remembering that 0, 0 is the *center* of the screen
	}

};