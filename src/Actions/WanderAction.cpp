#include "WanderAction.h"

#include "../Behavior/wander-steering.h"

//=======================================================================================================================
CWanderAction::CWanderAction(std::vector<SWeightedBehavior>& InWeightedBehaviors) :
	CAction(5.0, 5.0, true),
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
	WeightedBehaviors.clear();
	WeightedBehaviors.push_back(SWeightedBehavior(new cwander_steering(), 1));

	IsComplete = true;
}
