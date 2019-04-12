#pragma once

#include "Task.h"

//=======================================================================================================================
class CInverter : public CTask
{
public:
	CInverter(int InTaskId);
	~CInverter();

protected:
	virtual EStatus OnExecute(CTick* InTick) override;
};
