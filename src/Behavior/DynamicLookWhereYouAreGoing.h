#pragma once
#include "Behavior.h"

#include "DynamicAlign.h"

//=======================================================================================================================
class CDynamicLookWhereYouAreGoing : public CBehavior
{
public:
	CDynamicLookWhereYouAreGoing();
	~CDynamicLookWhereYouAreGoing();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	CDynamicAlign DynamicAlign;
};

