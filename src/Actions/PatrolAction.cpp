#include "PatrolAction.h"

#include "../Movement/basic-motion.h"
#include "../Movement/Behavior.h"

//=======================================================================================================================
CPatrolAction::CPatrolAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors) :
	CAction(5.0, 5.0, true),
	WeightedBehaviors(InWeightedBehaviors)
{

}

//=======================================================================================================================
CPatrolAction::~CPatrolAction()
{
}

//=======================================================================================================================
void CPatrolAction::Execute()
{
	for (auto Behavior : WeightedBehaviors)
	{
		delete Behavior;
	}

	WeightedBehaviors.clear();
	WeightedBehaviors.push_back(new SWeightedBehavior(new cbasic_motion(), 1));

	IsComplete = true;
	QueuedTime = 0.0;
}
