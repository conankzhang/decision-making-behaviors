#include "ActionNode.h"

#include "../Actions/Action.h"

CActionNode::CActionNode(CAction* InAction) :
	Action(InAction)
{

}

CActionNode::~CActionNode()
{
	if (Action)
	{
		delete Action;
	}
}

CDecisionTreeNode* CActionNode::MakeDecision()
{
	return this;
}
