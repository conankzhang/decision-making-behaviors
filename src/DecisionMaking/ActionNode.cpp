#include "ActionNode.h"

CActionNode::CActionNode(CAction* InAction) :
	Action(InAction)
{

}

CActionNode::~CActionNode()
{
}

CDecisionTreeNode* CActionNode::MakeDecision()
{
	return this;
}
