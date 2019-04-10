#include "basic-motion.h"

#include "../Entity/Boid.h"

#include "ofAppRunner.h"

//=======================================================================================================================
cbasic_motion::cbasic_motion() :
	WindowHeight(ofGetWindowHeight()),
	WindowWidth(ofGetWindowWidth()),
	Direction(EDirection::UP),
	MaxSpeed(100.0f)
{

}

//=======================================================================================================================
SBehaviorOutput cbasic_motion::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;
	BehaviorOutput.Dynamic = false;

	switch(Direction)
	{
	case EDirection::UP:
		if (InBoid.GetPosition().y < InBoid.GetSize())
		{
			Direction = EDirection::RIGHT;
		}
		else
		{
			BehaviorOutput.Linear.y = -MaxSpeed;
			break;
		}
	case EDirection::RIGHT:
		if (InBoid.GetPosition().x > WindowWidth - InBoid.GetSize())
		{
			Direction = EDirection::DOWN;
		}
		else
		{
			BehaviorOutput.Linear.x = MaxSpeed;
			break;
		}
	case EDirection::DOWN:
		if (InBoid.GetPosition().y > WindowHeight - InBoid.GetSize())
		{
			Direction = EDirection::LEFT;
		}
		else
		{
			BehaviorOutput.Linear.y = MaxSpeed;
			break;
		}
	case EDirection::LEFT:
		if (InBoid.GetPosition().x < InBoid.GetSize())
		{
			Direction = EDirection::STOP;
		}
		else
		{
			BehaviorOutput.Linear.x = -MaxSpeed;
			break;
		}
	}

	return BehaviorOutput;
}
