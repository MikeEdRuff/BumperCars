#pragma once
//edited by caleb bellisle

#pragma once
#include "UIScreen.h"
#include "FollowActor.h"
class Speedometer : public UIScreen
{
public:
	Speedometer(class Game* game);
	~Speedometer();

	
	void CalcSpeed(FollowActor* car);

private:
	//std::unordered_map<std::string, std::string> mText;

};