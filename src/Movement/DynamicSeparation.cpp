#include "DynamicSeparation.h"

#include "../Entity/Boid.h"

//=======================================================================================================================
CDynamicSeparation::CDynamicSeparation(const std::vector<CBoid *>* InTargets) :
	Targets(InTargets),
	Threshold(100.0f),
	K(100.0f),
	MaxAcceleration(500.0f)
{

}

//=======================================================================================================================
CDynamicSeparation::~CDynamicSeparation()
{
}

//=======================================================================================================================
SBehaviorOutput CDynamicSeparation::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	if (Targets)
	{
		for (auto Target : *Targets)
		{
			ofVec2f Direction = InBoid.GetPosition() - Target->GetPosition();
			float Distance = Direction.length();
			if (Distance < Threshold)
			{
				float Strength = MIN(K / Distance * Distance, MaxAcceleration);
				BehaviorOutput.Linear += Strength * Direction.getNormalized();
			}

		}

	}

	if (BehaviorOutput.Linear.length() > MaxAcceleration)
	{
		BehaviorOutput.Linear = BehaviorOutput.Linear.getNormalized() * MaxAcceleration;
	}

	return BehaviorOutput;
}
