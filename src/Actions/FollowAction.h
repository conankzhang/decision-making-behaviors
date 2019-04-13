#pragma once

#include "Action.h"
#include "../Movement/Behavior.h"

#include <vector>
#include <stack>

class CHeuristic;
class CDirectedWeightedGraph;
class CDirectedWeightedEdge;
class CDivisionScheme;
class CFlock;

//=======================================================================================================================
class CFollowAction : public CAction
{
public:
	CFollowAction(
		std::vector<SWeightedBehavior*>& InWeightedBehaviors,
		std::stack<const CDirectedWeightedEdge*>& InPath,
		CDivisionScheme* InDivisionScheme,
		const ofVec2f& InClickTarget,
		const CDirectedWeightedGraph* const InGraph,
		const CHeuristic* const InHeuristic);

	~CFollowAction();

	virtual void Execute() override;

	inline void SetCharacter(CFlock* InCharacter) { Character = InCharacter; }
	inline void SetMonster(CFlock* InMonster) { Monster = InMonster; }

private:
	std::vector<SWeightedBehavior*>& WeightedBehaviors;

	CDivisionScheme* DivisionScheme;
	std::stack<const CDirectedWeightedEdge*>& Path;
	const ofVec2f& ClickTarget;
	CFlock* Character;
	CFlock* Monster;

	const CDirectedWeightedGraph* const Graph;
	const CHeuristic* const Heuristic;
};
