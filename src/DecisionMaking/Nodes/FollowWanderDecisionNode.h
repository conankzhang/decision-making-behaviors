#pragma once

#include "../DecisionNode.h"

//=======================================================================================================================
class CFollowWanderDecisionNode : public CDecisionNode
{
public:
	CFollowWanderDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode);
	~CFollowWanderDecisionNode();

private:
	virtual bool IsTrue() override;
};
