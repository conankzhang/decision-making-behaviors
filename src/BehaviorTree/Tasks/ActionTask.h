#pragma once

#include "Task.h"

class CAction;

//=======================================================================================================================
class CActionTask : public CTask
{
public:
	CActionTask(size_t InTaskId, CAction* InAction);
	~CActionTask();

protected:
	virtual EStatus OnExecute(CTick* InTick) override;

	CAction* Action;
};

