#pragma once
#include "Behavior.h"

//=======================================================================================================================
class cseek_steering : public CBehavior
{
public:
	cseek_steering();
	cseek_steering(const ofVec2f& InTarget);
	~cseek_steering();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;
	inline void SetTarget(const ofVec2f& InTarget) { Target = InTarget; }

private:
	ofVec2f Target;

	float TargetRadius;
	float SlowRadius;
	float TimeToTarget;
};
