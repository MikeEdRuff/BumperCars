// ----------------------------------------------------------------
// From Game Programming in C++ by Sanjay Madhav
// Copyright (C) 2017 Sanjay Madhav. All rights reserved.
// 
// Released under the BSD License
// See LICENSE in root directory for full details.
// ----------------------------------------------------------------

#pragma once
#include <SDL/SDL.h>
#include <unordered_map>
#include <string>
#include <vector>
#include "Math.h"
#include "SoundEvent.h"
#include "FollowActor.h"
class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();
	void Shutdown();

	void AddActor(class Actor* actor);
	void RemoveActor(class Actor* actor);

	class Renderer* GetRenderer() { return mRenderer; }
	class AudioSystem* GetAudioSystem() { return mAudioSystem; }
	// Manage UI stack
	const std::vector<class UIScreen*>& GetUIStack() { return mUIStack; }		//Caleb Bellisle
	void PushUI(class UIScreen* screen);		//Caleb Bellisle

	enum GameState		//Caleb Bellisle
	{
		EStart,
		EGameplay,
		EPaused,
		EQuit
	};

	GameState GetState() const { return mGameState; }		//Caleb Bellisle
	void SetState(GameState state) { mGameState = state; }		//Caleb Bellisle

	class Font* GetFont(const std::string& fileName);

	void LoadText(const std::string& fileName);
	const std::string& GetText(const std::string& key);
	class FollowActor& GetPlayerCar() { return *mFollowActor; }	//Carl McAninch
	std::vector<class SphereActor*>& GetSpheres() { return mSphereActors; } //Jackson Wise

	void AddSphere(SphereActor* sphere); // Jackson Wise
	
private:
	void ProcessInput();
	void HandleKeyPress(int key);
	void UpdateGame();
	void GenerateOutput();
	void LoadData();
	void UnloadData();


	// All the actors in the game
	std::vector<class Actor*> mActors;
	std::vector<class UIScreen*> mUIStack;		//Caleb Bellisle
	std::unordered_map<std::string, class Font*> mFonts;
	// Map for text localization
	std::unordered_map<std::string, std::string> mText;
	// Any pending actors
	std::vector<class Actor*> mPendingActors;
	class Renderer* mRenderer;
	class AudioSystem* mAudioSystem;

	Uint32 mTicksCount;
	GameState mGameState;
	// Track if we're updating actors right now
	bool mUpdatingActors;


	// Game-specific code
	class Speedometer* mSpeedometer;		//Caleb Bellisle

	class SkyBox* mySkyBox;
	class AiCar* mAiCarOne;
	class AiCar* mAiCarTwo;
	class AiCar* mAiCarThree;
	class FollowActor* mFollowActor;
	std::vector<class SphereActor*> mSphereActors; // Jackson Wise
	class OrbitActor* mOrbitActor;
	class SplineActor* mSplineActor;
	class Actor* mStartSphere;
	class Actor* mEndSphere;
	class SpriteComponent* mCrosshair;
	SoundEvent mMusicEvent;
	SoundEvent mReverbSnap;
};
