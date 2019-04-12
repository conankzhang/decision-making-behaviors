#include "Flock.h"

#include "../Entity/Boid.h"
#include "../Behavior/Behavior.h"

#include "../DecisionMaking/DecisionMakingBehavior.h"

//=======================================================================================================================
CFlock::CFlock(int InFlockCount, const std::vector<SWeightedBehavior*>& InWeightedBehaviors, const ofColor& InFlockColor, CDecisionMakingBehavior* InDecisionMakingBehavior) :
	WeightedBehaviors(InWeightedBehaviors),
	FlockColor(InFlockColor),
	DecisionMakingBehavior(InDecisionMakingBehavior)
{
	Boids.reserve(InFlockCount);
	for (int i = 0; i < InFlockCount; i++)
	{
		Boids.push_back(new CBoid(this));
	}

	SetBehavior(EBehavior::WANDER);
}

//=======================================================================================================================
CFlock::~CFlock()
{
	for (auto Boid : Boids)
	{
		delete Boid;
	}

	Boids.clear();

	if (DecisionMakingBehavior)
	{
		delete DecisionMakingBehavior;
	}
}

//=======================================================================================================================
void CFlock::Update(double DeltaTime)
{
	ActionManager.Update(DeltaTime);
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
void CFlock::SetBehavior(EBehavior InBehavior)
{
	Behavior = InBehavior;

	if (DecisionMakingBehavior)
	{
		ActionManager.ScheduleAction(DecisionMakingBehavior->GetAction());
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
		if (WeightedBehavior && WeightedBehavior->Behavior)
		{
			SBehaviorOutput BehaviorOutput = WeightedBehavior->Behavior->GetBehaviorOutput(InBoid);
			ReturnBehaviorOutput.Linear += BehaviorOutput.Linear * WeightedBehavior->Weight;
			ReturnBehaviorOutput.Angular += BehaviorOutput.Angular * WeightedBehavior->Weight;
			if (!BehaviorOutput.Dynamic)
			{
				ReturnBehaviorOutput.Dynamic = false;
			}
		}
	}

	return ReturnBehaviorOutput;
}
