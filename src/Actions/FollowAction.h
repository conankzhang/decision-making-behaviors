#pragma once

#include "Action.h"
#include "../Movement/Behavior.h"

#include <vector>
#include <stack>

class CDirectedWeightedEdge;
class CDivisionScheme;

//=======================================================================================================================
class CFollowAction : public CAction
{
public:
	CFollowAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, std::stack<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme, const ofVec2f& InClickTarget);
	~CFollowAction();

	virtual void Execute() override;

private:
	std::vector<SWeightedBehavior*>& WeightedBehaviors;

	CDivisionScheme* DivisionScheme;
	std::stack<const CDirectedWeightedEdge*>& Path;
	const ofVec2f& ClickTarget;
};
