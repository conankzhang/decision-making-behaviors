#pragma once

#include "../DecisionMaking/DecisionMakingBehavior.h"

class CTask;
class CBlackBoard;
class CAction;

//=======================================================================================================================
class CBehaviorTree : public CDecisionMakingBehavior
{
public:
	CBehaviorTree(size_t InTreeId, CTask* InRootTask, CBlackBoard* InBlackBoard);
	~CBehaviorTree();

	inline size_t GetTreeId() const { return TreeId; }
	virtual CAction* GetAction() override;

private:
	size_t TreeId;
	CTask* RootTask;
	CBlackBoard* BlackBoard;
};
