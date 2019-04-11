#pragma once

#include "Action.h"
#include "../Behavior/Behavior.h"

#include <vector>

//=======================================================================================================================
class CWanderAction : public CAction
{
public:
	CWanderAction(std::vector<SWeightedBehavior>& InWeightedBehaviors);
	~CWanderAction();

	virtual void Execute() override;

private:
	std::vector<SWeightedBehavior>& WeightedBehaviors;
};
