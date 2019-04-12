#include "FollowWanderDecisionNode.h"

#include "../../Entity/Flock.h"

//=======================================================================================================================
CFollowWanderDecisionNode::CFollowWanderDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode) :
	CDecisionNode(InTrueNode, InFalseNode),
	Flock(nullptr)
{

}

//=======================================================================================================================
CFollowWanderDecisionNode::~CFollowWanderDecisionNode()
{
}

//=======================================================================================================================
bool CFollowWanderDecisionNode::IsTrue()
{
	if (!Flock)
	{
		return false;
	}

	if (Flock->GetBehavior() == EBehavior::FOLLOW)
	{
		return true;
	}
	else
	{
		return false;
	}
}
