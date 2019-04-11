#include "DecisionNode.h"

CDecisionNode::CDecisionNode(CDecisionTreeNode* InTrueNode, CDecisionTreeNode* InFalseNode) :
	TrueNode(InTrueNode),
	FalseNode(InFalseNode)
{

}

CDecisionNode::~CDecisionNode()
{
	if (TrueNode)
	{
		delete TrueNode;
	}

	if (FalseNode)
	{
		delete FalseNode;
	}
}

CDecisionTreeNode* CDecisionNode::MakeDecision()
{
	CDecisionTreeNode* Branch = GetBranch();
	if (Branch)
	{
		return Branch->MakeDecision();
	}
}
