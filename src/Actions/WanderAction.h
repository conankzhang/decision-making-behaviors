#pragma once

#include "Action.h"
#include <vector>

class CObstacle;
struct SWeightedBehavior;

//=======================================================================================================================
class CWanderAction : public CAction
{
public:
	CWanderAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, const std::vector<CObstacle*>& InObstacles);
	~CWanderAction();

	virtual void Execute() override;

private:
	std::vector<SWeightedBehavior*>& WeightedBehaviors;
	const std::vector<CObstacle*>& Obstacles;
};
