//edited by Julian Powell

#include "Radar.h"
#include "Actor.h"
#include "Game.h"
#include "DialogBox.h"
#include "SphereActor.h"
#include "AiCar.h"
#include <SDL/SDL.h>
#include <rapidjson/document.h>
#include <string>
#include "Renderer.h"
#include "UIScreen.h"
#include "TargetComponent.h" //Will Briggs

Radar::Radar(Game* game)
	:UIScreen(game, 0.0, 0.0f),
	mRadarRange(2000.0f),
	mRadarRadius(92.0f)
{
	Renderer* r = mGame->GetRenderer();
	mRadar = r->GetTexture("Assets/Radar.png");
	mBlipTex = r->GetTexture("Assets/Blip.png");
	mRadarArrow = r->GetTexture("Assets/RadarArrow.png");
}

void Radar::Update(float deltaTime)
{
	UIScreen::Update(deltaTime);
	UpdateRadar(deltaTime);
}

void Radar::Draw(Shader* shader)
{
	// Radar
	const Vector2 cRadarPos(-370.0f, -170.0f);
	DrawTexture(shader, mRadar, cRadarPos, 0.75f);
	// Blips
	for (Vector2& blip : mBlips)
	{
		DrawTexture(shader, mBlipTex, cRadarPos + blip, 1.0f);
	}
	// Radar arrow
	DrawTexture(shader, mRadarArrow, cRadarPos);
}

void Radar::UpdateRadar(float deltaTime)
{
	// Clear blip positions from last frame
	mBlips.clear();

	// Convert player position to radar coordinates (x forward, z up)
	Vector3 playerPos = mGame->GetPlayerCar().GetPosition();
	Vector2 playerPos2D(playerPos.y, playerPos.x);
	// Ditto for player forward
	Vector3 playerForward = mGame->GetPlayerCar().GetForward();
	Vector2 playerForward2D(playerForward.x, playerForward.y);

	// Use atan2 to get rotation of radar
	float angle = Math::Atan2(playerForward2D.y, playerForward2D.x);
	// Make a 2D rotation matrix
	Matrix3 rotMat = Matrix3::CreateRotation(angle);

	// Get positions of blips
	for (auto tc : mTargetComps) //Will Briggs restored 2023-04-14
	{
		Vector3 carPos = tc->GetOwner()->GetPosition();
		Vector2 actorPos2D(carPos.y, carPos.x);

		// Calculate vector between player and target
		Vector2 playerToCar = actorPos2D - playerPos2D;

		// See if within range
		if (playerToCar.LengthSq() <= (mRadarRange * mRadarRange))
		{
			// Convert playerToTarget into an offset from
			// the center of the on-screen radar
			Vector2 blipPos = playerToCar;
			blipPos *= mRadarRadius / mRadarRange;

			// Rotate blipPos
			blipPos = Vector2::Transform(blipPos, rotMat);
			mBlips.emplace_back(blipPos);
		}
	}
}
Radar::~Radar()
{
}

void Radar::AddTargetComponent(TargetComponent* tc)
{
	mTargetComps.emplace_back(tc);
}

void Radar::RemoveTargetComponent(TargetComponent* tc)
{
	auto iter = std::find(mTargetComps.begin(), mTargetComps.end(),
		tc);
	mTargetComps.erase(iter);
}