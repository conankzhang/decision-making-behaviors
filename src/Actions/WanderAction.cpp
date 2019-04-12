#include "WanderAction.h"

#include "../Movement/wander-steering.h"

//=======================================================================================================================
CWanderAction::CWanderAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, const std::vector<CObstacle*>& InObstacles) :
	CAction(5.0, 5.0, false),
	WeightedBehaviors(InWeightedBehaviors),
	Obstacles(InObstacles)
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
	WeightedBehaviors.push_back(new SWeightedBehavior(new cwander_steering(Obstacles), 1));

	IsComplete = true;
}
