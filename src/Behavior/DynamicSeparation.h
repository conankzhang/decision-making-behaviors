#pragma once
#include "Behavior.h"

class CBoid;
//=======================================================================================================================
class CDynamicSeparation : public CBehavior
{
public:
	CDynamicSeparation(const std::vector<CBoid *>* InTargets);
	~CDynamicSeparation();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	const std::vector<CBoid *>* Targets;

	float Threshold;
	float MaxAcceleration;
	float K;
};

