#pragma once

#include "Task.h"

//=======================================================================================================================
class CSequencer : public CTask
{
public:
	CSequencer(size_t InTaskId);
	~CSequencer();

protected:
	virtual void OnOpen(CTick* InTick) override;
	virtual EStatus OnExecute(CTick* InTick) override;
};
