#pragma once

#include "DecisionTreeNode.h"

class CDecisionNode : public CDecisionTreeNode
{
public:
	CDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode);
	~CDecisionNode();

	virtual CDecisionTreeNode* MakeDecision() override;

private:
	inline CDecisionTreeNode* GetBranch() { return IsTrue() ? TrueNode : FalseNode; }

	virtual bool IsTrue() = 0;

private:
	CDecisionTreeNode* TrueNode;
	CDecisionTreeNode* FalseNode;
};
