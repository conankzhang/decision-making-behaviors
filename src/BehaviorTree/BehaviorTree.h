#pragma once

class CTask;
class CBlackBoard;
class CAction;

//=======================================================================================================================
class CBehaviorTree
{
public:
	CBehaviorTree(int InTreeId, CTask* InRoot, CBlackBoard* InBlackBoard);
	~CBehaviorTree();

	inline int GetTreeId() const { return TreeId; }
	CAction* GetAction();

private:
	int TreeId;
	CTask* Root;
	CBlackBoard* BlackBoard;
};
