#include "wander-steering.h"

#include "../Entity/Boid.h"

//=======================================================================================================================
cwander_steering::cwander_steering() :
	MaxSpeed(150.0f),
	MaxRotation(6.0f)
{

}

//=======================================================================================================================
cwander_steering::~cwander_steering()
{
}

//=======================================================================================================================
SBehaviorOutput cwander_steering::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	ofVec2f Direction = ofVec2f::zero();
	Direction.x = cos(InBoid.GetOrientation());
	Direction.y = sin(InBoid.GetOrientation());

	ofVec2f TargetVelocity = Direction * MaxSpeed;
	BehaviorOutput.Linear = TargetVelocity - InBoid.GetVelocity();

	float TargetOrientation = InBoid.GetOrientation() + (MaxRotation * RandomBinomial());

	DynamicAlign.SetTargetOrientation(TargetOrientation);

	BehaviorOutput.Angular = DynamicAlign.GetBehaviorOutput(InBoid).Angular;

	return BehaviorOutput;
}

float cwander_steering::RandomBinomial()
{
	return static_cast<float>(rand()) - static_cast<float>(rand());
}
