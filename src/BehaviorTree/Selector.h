#pragma once

#include "Task.h"

//=======================================================================================================================
class CSelector : public CTask
{
public:
	CSelector();
	~CSelector();
private:
	virtual void OnOpen(CTick* InTick) override;
	virtual EStatus OnExecute(CTick* InTick) override;
};

