#include "DecisionMakingBehavior.h"

#include "DecisionTreeNode.h"
#include "ActionNode.h"

CDecisionMakingBehavior::CDecisionMakingBehavior(CDecisionTreeNode* InRoot) :
	Root(InRoot)
{

}

CDecisionMakingBehavior::~CDecisionMakingBehavior()
{
}

CAction* CDecisionMakingBehavior::GetAction()
{
	if (!Root)
	{
		return nullptr;
	}

	CDecisionTreeNode* Node = Root->MakeDecision();

	if (!Node)
	{
		return nullptr;
	}

	return static_cast<CActionNode*>(Node)->GetAction();
}
