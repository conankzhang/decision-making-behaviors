#include "FollowWanderDecisionTree.h"

#include "DecisionMakingBehavior.h"
#include "Nodes/FollowWanderDecisionNode.h"

#include "ActionNode.h"
#include "../Actions/FollowAction.h"
#include "../Actions/WanderAction.h"


//=======================================================================================================================
CFollowWanderDecisionTree::CFollowWanderDecisionTree()
{
	CActionNode* FollowActionNode = new CActionNode(new CFollowAction());
	CActionNode* WanderActionNode = new CActionNode(new CWanderAction());

	CFollowWanderDecisionNode* Root = new CFollowWanderDecisionNode(FollowActionNode, WanderActionNode);

	DecisionTree = new CDecisionMakingBehavior(Root);
}

//=======================================================================================================================
CFollowWanderDecisionTree::~CFollowWanderDecisionTree()
{
	if (DecisionTree)
	{
		delete DecisionTree;
	}
}
