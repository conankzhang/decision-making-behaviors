#include "seek-steering.h"

#include "../Entity/Boid.h"

//=======================================================================================================================
cseek_steering::cseek_steering() :
	Target(ofVec2f::zero()),
	TargetRadius(10.0f),
	SlowRadius(100.0f),
	TimeToTarget(5.0f)
{

}

//=======================================================================================================================
cseek_steering::cseek_steering(const ofVec2f& InTarget) :
	Target(InTarget),
	TargetRadius(10.0f),
	SlowRadius(100.0f),
	TimeToTarget(5.0f)
{

}

//=======================================================================================================================
cseek_steering::~cseek_steering()
{
}

//=======================================================================================================================
SBehaviorOutput cseek_steering::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	ofVec2f Direction = Target - InBoid.GetPosition();
	float Distance = Direction.length();

	if (Distance < TargetRadius)
	{
		return BehaviorOutput;
	}

	float TargetSpeed = 0.0f;
	if (Distance > SlowRadius)
	{
		TargetSpeed = InBoid.GetMaxSpeed();
	}
	else
	{
		TargetSpeed = InBoid.GetMaxSpeed() * (Distance - TargetRadius) / (SlowRadius - TargetRadius);
	}

	ofVec2f TargetVelocity = Direction.getNormalized() * TargetSpeed;
	BehaviorOutput.Linear = TargetVelocity - InBoid.GetVelocity();

	return BehaviorOutput;
}
