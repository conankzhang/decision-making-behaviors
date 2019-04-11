#pragma once

#include "Action.h"

//=======================================================================================================================
class CWanderAction : public CAction
{
public:
	CWanderAction();
	~CWanderAction();

	virtual void Execute() override;
};
