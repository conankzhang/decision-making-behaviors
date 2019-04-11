#pragma once

#include "DecisionTreeNode.h"

class CAction;

class CActionNode : public CDecisionTreeNode
{
public:
	CActionNode(CAction* InAction);
	~CActionNode();

	virtual CDecisionTreeNode* MakeDecision() override;
	inline CAction* GetAction() { return Action; }

private:
	CAction* Action;
};

