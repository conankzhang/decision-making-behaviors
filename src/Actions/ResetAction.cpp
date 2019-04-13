#include "ResetAction.h"

#include "../Movement/wander-steering.h"
#include "../Movement/Behavior.h"

#include "../Entity/Flock.h"

//=======================================================================================================================
CResetAction::CResetAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, const std::vector<CObstacle*>& InObstacles, CFlock* InCharacter) :
	CAction(5.0, 5.0, true),
	WeightedBehaviors(InWeightedBehaviors),
	Obstacles(InObstacles),
	Character(InCharacter),
	Monster(nullptr)
{

}

//=======================================================================================================================
CResetAction::~CResetAction()
{
}

//=======================================================================================================================
void CResetAction::Execute()
{
	for (auto Behavior : WeightedBehaviors)
	{
		delete Behavior;
	}
	WeightedBehaviors.clear();
	WeightedBehaviors.push_back(new SWeightedBehavior(new cwander_steering(Obstacles), 1));

	Character->ResetPosition();
	Monster->ResetPosition();

	IsComplete = true;
	QueuedTime = 0.0;
}
