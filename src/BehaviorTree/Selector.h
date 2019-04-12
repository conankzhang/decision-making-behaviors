#pragma once

#include "Task.h"

//=======================================================================================================================
class CSelector : public CTask
{
public:
	CSelector(int InTaskId);
	~CSelector();

protected:
	virtual void OnOpen(CTick* InTick) override;
	virtual EStatus OnExecute(CTick* InTick) override;
};

