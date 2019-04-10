#pragma once

#include "ofVec2f.h"

class CBoid;

//=======================================================================================================================
struct SBehaviorOutput
{
	ofVec2f Linear;
	float Angular;
	bool Dynamic;

	SBehaviorOutput();
};

//=======================================================================================================================
class CBehavior
{
public:
	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) = 0;
};

//=======================================================================================================================
struct SWeightedBehavior
{
	CBehavior* Behavior;
	float Weight;

	SWeightedBehavior(CBehavior* InBehavior, float InWeight);
};
