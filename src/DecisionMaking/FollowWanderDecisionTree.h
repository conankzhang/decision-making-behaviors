#pragma once

class CDecisionMakingBehavior;

//=======================================================================================================================
class CFollowWanderDecisionTree
{
public:
	CFollowWanderDecisionTree();
	~CFollowWanderDecisionTree();

private:
	CDecisionMakingBehavior* DecisionTree;
};
