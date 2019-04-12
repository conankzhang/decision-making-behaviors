#pragma once
#include "Behavior.h"

#include "DynamicAlign.h"

//=======================================================================================================================
class CDynamicFace : public CBehavior
{
public:
	CDynamicFace(ofVec2f InTarget);
	~CDynamicFace();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	CDynamicAlign DynamicAlign;
	ofVec2f Target;
};
