#pragma once
//edited by Julian Powell

#pragma once
#include "UIScreen.h"
#include "FollowActor.h"
class Radar : public UIScreen
{
public:
	Radar(class Game* game);
	~Radar();
	void Draw(class Shader* shader) override;
	void Update(float deltaTime) override;


protected:
	void UpdateRadar(float deltaTime);

	class Texture* mRadar;
	class Texture* mBlipTex;
	class Texture* mRadarArrow;

	std::vector<Vector2> mBlips;
	// Adjust range of radar and radius
	float mRadarRange;
	float mRadarRadius;
};