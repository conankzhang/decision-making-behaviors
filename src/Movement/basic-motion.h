#pragma once

#include "Behavior.h"

//=======================================================================================================================
enum class EDirection
{
	UP,
	RIGHT,
	DOWN,
	LEFT,
	STOP
};

//=======================================================================================================================
class cbasic_motion : public CBehavior
{
public:
	cbasic_motion();

	virtual SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid) override;

private:
	int WindowHeight;
	int WindowWidth;

	EDirection Direction;

	float MaxSpeed;
};
