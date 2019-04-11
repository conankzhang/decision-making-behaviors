#include "WanderAction.h"

#include "../Behavior/wander-steering.h"

//=======================================================================================================================
CWanderAction::CWanderAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors) :
	CAction(5.0, 5.0, false),
	WeightedBehaviors(InWeightedBehaviors)
{

}

//=======================================================================================================================
CWanderAction::~CWanderAction()
{
}

//=======================================================================================================================
void CWanderAction::Execute()
{
	for (auto Behavior : WeightedBehaviors)
	{
		delete Behavior;
	}
	WeightedBehaviors.clear();
	WeightedBehaviors.push_back(new SWeightedBehavior(new cwander_steering(), 1));

	IsComplete = true;
}
