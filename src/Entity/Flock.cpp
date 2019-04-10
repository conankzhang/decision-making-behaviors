#include "Flock.h"

#include "../Entity/Boid.h"
#include "../Behavior/Behavior.h"

//=======================================================================================================================
CFlock::CFlock(int InFlockCount, const std::vector<SWeightedBehavior>& InWeightedBehaviors, const ofColor& InFlockColor) :
	WeightedBehaviors(InWeightedBehaviors),
	FlockColor(InFlockColor)
{
	Boids.reserve(InFlockCount);
	for (int i = 0; i < InFlockCount; i++)
	{
		Boids.push_back(new CBoid());
	}
}

//=======================================================================================================================
CFlock::~CFlock()
{
	for (auto Boid : Boids)
	{
		delete Boid;
	}

	Boids.clear();
}

//=======================================================================================================================
void CFlock::Update(float DeltaTime)
{
	UpdateCenterOfMass();
	for (auto Boid : Boids)
	{
		if (Boid)
		{
			SBehaviorOutput BehaviorOutput = GetBehaviorOutput(*Boid);
			Boid->Update(BehaviorOutput, DeltaTime);
		}
	}
}

//=======================================================================================================================
void CFlock::Draw() const
{
	for (auto Boid : Boids)
	{
		if (Boid)
		{
			Boid->Draw(FlockColor);
		}
	}
}

//=======================================================================================================================
void CFlock::UpdateCenterOfMass()
{
	CenterOfMass = ofVec2f::zero();

	for (auto Boid : Boids)
	{
		CenterOfMass += Boid->GetPosition();
	}

	CenterOfMass /= Boids.size();
}

//=======================================================================================================================
SBehaviorOutput CFlock::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput ReturnBehaviorOutput;

	for (auto WeightedBehavior : WeightedBehaviors)
	{
		if (WeightedBehavior.Behavior)
		{
			SBehaviorOutput BehaviorOutput = WeightedBehavior.Behavior->GetBehaviorOutput(InBoid);
			ReturnBehaviorOutput.Linear += BehaviorOutput.Linear * WeightedBehavior.Weight;
			ReturnBehaviorOutput.Angular += BehaviorOutput.Angular * WeightedBehavior.Weight;
			if (!BehaviorOutput.Dynamic)
			{
				ReturnBehaviorOutput.Dynamic = false;
			}
		}
	}

	return ReturnBehaviorOutput;
}
