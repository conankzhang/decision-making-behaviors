#pragma once

#include "../DecisionMaking/DecisionMakingBehavior.h"

class CTask;
class CBlackBoard;
class CAction;

//=======================================================================================================================
class CBehaviorTree : public CDecisionMakingBehavior
{
public:
	CBehaviorTree(int InTreeId, CTask* InRootTask, CBlackBoard* InBlackBoard);
	~CBehaviorTree();

	inline int GetTreeId() const { return TreeId; }
	virtual CAction* GetAction() override;

private:
	int TreeId;
	CTask* RootTask;
	CBlackBoard* BlackBoard;
};
