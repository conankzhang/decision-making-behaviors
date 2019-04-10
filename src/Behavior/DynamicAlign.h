#pragma once
#include "Behavior.h"

//=======================================================================================================================
class CDynamicAlign : public CBehavior
{
public:
	CDynamicAlign();
	~CDynamicAlign();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
	inline void SetTargetOrientation(float InTargetOrientation) { TargetOrientation = InTargetOrientation; }
private:
	float MapToRange(float InRotation);

	float TargetOrientation;
	float TargetAngleThreshold;
	float SlowAngleThreshold;
	float TimeToTarget;
	float MaxRotation;
	float MaxAngularAcceleration;
};

