#include "FollowWanderDecisionNode.h"

//=======================================================================================================================
CFollowWanderDecisionNode::CFollowWanderDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode) :
	CDecisionNode(InTrueNode, InFalseNode)
{

}

//=======================================================================================================================
CFollowWanderDecisionNode::~CFollowWanderDecisionNode()
{
}

//=======================================================================================================================
bool CFollowWanderDecisionNode::IsTrue()
{
	return false;
}
