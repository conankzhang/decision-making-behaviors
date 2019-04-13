#pragma once

#include "Task.h"

//=======================================================================================================================
class CRandomizer : public CTask
{
public:
	CRandomizer(size_t InTaskId);
	~CRandomizer();

protected:
	virtual void OnOpen(CTick* InTick) override;
	virtual EStatus OnExecute(CTick* InTick) override;
};

