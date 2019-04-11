#pragma once

class CDecisionTreeNode
{
public:
	virtual CDecisionTreeNode* MakeDecision() = 0;
};