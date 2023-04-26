//edited by Julian Powell

#pragma once
#include "UIScreen.h"
class Radar : public UIScreen
{
public:
	Radar(class Game* game);
	~Radar();
	void Draw(class Shader* shader) override;
	void Update(float deltaTime) override;

	void AddTargetComponent(class TargetComponent* tc);

	void RemoveTargetComponent(class TargetComponent* tc);
protected:
	void UpdateRadar(float deltaTime);

	class Texture* mRadar;
	class Texture* mBlipTex;
	class Texture* mRadarArrow;

	// All the target components in the game
	std::vector<class TargetComponent*> mTargetComps;
	// 2D offsets of blips relative to radar
	std::vector<Vector2> mBlips;
	// Adjust range of radar and radius
	float mRadarRange;
	float mRadarRadius;
};

