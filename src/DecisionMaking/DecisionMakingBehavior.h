#pragma once

class CAction;
class CDecisionTreeNode;

//=======================================================================================================================
class CDecisionMakingBehavior
{
public:
	CDecisionMakingBehavior();
	CDecisionMakingBehavior(CDecisionTreeNode* InRoot);
	~CDecisionMakingBehavior();

	virtual CAction* GetAction();

private:
	CDecisionTreeNode* Root;
};

