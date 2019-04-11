#pragma once

class CAction;
class CDecisionTreeNode;

class CDecisionMakingBehavior
{
public:
	CDecisionMakingBehavior(CDecisionTreeNode* InRoot);
	~CDecisionMakingBehavior();

	CAction* GetAction();

private:
	CDecisionTreeNode* Root;
};

