#pragma once

#include "Task.h"

//=======================================================================================================================
class CInverter : public CTask
{
public:
	CInverter(size_t InTaskId);
	~CInverter();

protected:
	virtual EStatus OnExecute(CTick* InTick) override;
};
