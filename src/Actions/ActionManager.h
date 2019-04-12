#pragma once

#include "PriorityQueue.h"

#include "Action.h"
#include <vector>

//=======================================================================================================================
class CActionManager
{
public:
	CActionManager();
	~CActionManager();

	void ScheduleAction(CAction* InAction);
	void Update(double InDeltaTime);

private:
	CPriorityQueue<CAction*, std::vector<CAction*>, SCompareAction> PendingActions;
	CPriorityQueue<CAction*, std::vector<CAction*>, SCompareAction> ActiveActions;
};
