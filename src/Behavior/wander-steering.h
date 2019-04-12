#pragma once
#include "Behavior.h"

#include "DynamicAlign.h"

class CObstacle;

//=======================================================================================================================
class cwander_steering : public CBehavior
{
public:
	cwander_steering(const std::vector<CObstacle*>& InObstacles);
	~cwander_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	float RandomBinomial();

private:
	CDynamicAlign DynamicAlign;
	float MaxSpeed;
	float MaxRotation;

	const std::vector<CObstacle*>& Obstacles;
};

