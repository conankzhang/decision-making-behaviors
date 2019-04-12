#pragma once

#include "Task.h"
#include <memory>

class CAction;

//=======================================================================================================================
class CWanderTask : public CTask
{
public:
	CWanderTask(size_t InTaskId, CAction* InAction);
	~CWanderTask();

protected:
	virtual EStatus OnExecute(CTick* InTick) override;

	CAction* Action;
};

