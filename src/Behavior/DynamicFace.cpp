#include "DynamicFace.h"

#include "../Entity/Boid.h"
//=======================================================================================================================
CDynamicFace::CDynamicFace(ofVec2f InTarget) :
	Target(InTarget)
{
}

//=======================================================================================================================
CDynamicFace::~CDynamicFace()
{
}

//=======================================================================================================================
SBehaviorOutput CDynamicFace::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	ofVec2f Direction = Target - InBoid.GetPosition();
	if (Direction.length() == 0)
	{
		return BehaviorOutput;
	}

	float TargetOrientation = atan2(Direction.y, Direction.x);

	DynamicAlign.SetTargetOrientation(TargetOrientation);
	BehaviorOutput = DynamicAlign.GetBehaviorOutput(InBoid);

	return BehaviorOutput;
}
