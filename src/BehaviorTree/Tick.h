#pragma once

#include <set>

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

	inline void OpenTask(CTask* InTask) { OpenTasks.insert(InTask); }
	inline void CloseTask(CTask* InTask) { OpenTasks.erase(InTask); }

private:
	CBehaviorTree* BehaviorTree;
	CBlackBoard* BlackBoard;

	std::set<CTask*> OpenTasks;
};
