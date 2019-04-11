#pragma once

#include "Action.h"

//=======================================================================================================================
class CFollowAction : public CAction
{
public:
	CFollowAction();
	~CFollowAction();

	virtual void Execute() override;
};
