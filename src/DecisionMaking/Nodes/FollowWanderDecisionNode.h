#pragma once

#include "../DecisionNode.h"

class CFlock;

//=======================================================================================================================
class CFollowWanderDecisionNode : public CDecisionNode
{
public:
	CFollowWanderDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode);
	~CFollowWanderDecisionNode();

	inline void SetFlock(CFlock* InFlock) { Flock = InFlock; }

private:
	virtual bool IsTrue() override;

private:
	CFlock * Flock;
};
