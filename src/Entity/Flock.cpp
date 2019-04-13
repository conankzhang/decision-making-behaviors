#include "Flock.h"

#include "../Entity/Boid.h"
#include "../Movement/Behavior.h"

#include "../DecisionMaking/DecisionMakingBehavior.h"
#include "../BehaviorTree/BehaviorTree.h"

//=======================================================================================================================
CFlock::CFlock(int InFlockCount, const std::vector<SWeightedBehavior*>& InWeightedBehaviors, const ofColor& InColor, CDecisionMakingBehavior* InDecisionMakingBehavior, const ofVec2f& InInitialPosition) :
	WeightedBehaviors(InWeightedBehaviors),
	FlockColor(InColor),
	DecisionMakingBehavior(InDecisionMakingBehavior),
	bIsMonster(false),
	InitialPosition(InInitialPosition)
{
	Boids.reserve(InFlockCount);
	for (int i = 0; i < InFlockCount; i++)
	{
		Boids.push_back(new CBoid(this, InitialPosition));
	}

	if (static_cast<CBehaviorTree*>(DecisionMakingBehavior))
	{
		bIsMonster = true;
	}

	if (!bIsMonster)
	{
		SetBehavior(EBehavior::WANDER);
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

	if (DecisionMakingBehavior)
	{
		delete DecisionMakingBehavior;
	}
}

//=======================================================================================================================
void CFlock::Update(double DeltaTime)
{
	if (bIsMonster && DecisionMakingBehavior)
	{
		ActionManager.ScheduleAction(DecisionMakingBehavior->GetAction());
	}

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
void CFlock::ResetPosition()
{
	for (auto Boid : Boids)
	{
		Boid->SetPosition(InitialPosition);
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
