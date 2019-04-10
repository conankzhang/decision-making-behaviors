#pragma once
#include "Behavior.h"

#include "seek-steering.h"

#include <stack>

class CDivisionScheme;
class CDirectedWeightedEdge;

//=======================================================================================================================
class CDynamicPathFollow : public CBehavior
{
public:
	CDynamicPathFollow(std::stack<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme, const ofVec2f& InClickTarget);
	~CDynamicPathFollow();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	cseek_steering SeekSteering;

	CDivisionScheme* DivisionScheme;
	std::stack<const CDirectedWeightedEdge*>& Path;

	float TargetRadius;

	const ofVec2f& ClickTarget;
};
