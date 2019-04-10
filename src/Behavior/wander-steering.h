#pragma once
#include "Behavior.h"

#include "DynamicAlign.h"

//=======================================================================================================================
class cwander_steering : public CBehavior
{
public:
	cwander_steering();
	~cwander_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	float RandomBinomial();

	CDynamicAlign DynamicAlign;
	float MaxSpeed;
	float MaxRotation;
};

