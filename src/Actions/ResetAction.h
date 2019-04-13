#pragma once

#include "Action.h"
#include <vector>

class CObstacle;
class CFlock;
struct SWeightedBehavior;

//=======================================================================================================================
class CResetAction : public CAction
{
public:
	CResetAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, const std::vector<CObstacle*>& InObstacles, CFlock* InCharacter);
	~CResetAction();

	virtual void Execute() override;
	inline void SetMonster(CFlock* InMonster) { Monster = InMonster; }

private:
	std::vector<SWeightedBehavior*>& WeightedBehaviors;
	const std::vector<CObstacle*>& Obstacles;
	CFlock* Character;
	CFlock* Monster;
};

