#pragma once

class CBehaviorTree;
class CBlackBoard;

class CTask;

//=======================================================================================================================
class CTick
{
public:
	CTick(CBehaviorTree* InBehaviorTree, CBlackBoard* InBlackBoard);
	~CTick();

	inline CBlackBoard* GetBlackBoard(){ return BlackBoard; }
	inline CBehaviorTree* GetBehaviorTree(){ return BehaviorTree; }

private:
	CBehaviorTree* BehaviorTree;
	CBlackBoard* BlackBoard;
};
