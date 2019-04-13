#pragma once

#include "Action.h"

#include <vector>

struct SWeightedBehavior;

//=======================================================================================================================
class CPatrolAction : public CAction
{
public:
	CPatrolAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors);
	~CPatrolAction();

	virtual void Execute() override;

private:
	std::vector<SWeightedBehavior*>& WeightedBehaviors;
};
