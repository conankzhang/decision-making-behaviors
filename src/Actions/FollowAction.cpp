#include "FollowAction.h"

#include "../Movement/DynamicLookWhereYouAreGoing.h"
#include "../Movement/DynamicPathFollow.h"
#include "../Entity/Flock.h"

#include "../Pathfinding/Pathfinding.h"
#include "../Pathfinding/TiledDivisionScheme.h"

//=======================================================================================================================
CFollowAction::CFollowAction(
	std::vector<SWeightedBehavior*>& InWeightedBehaviors,
	std::stack<const CDirectedWeightedEdge*>& InPath,
	CDivisionScheme* InDivisionScheme,
	const ofVec2f& InClickTarget,
	const CDirectedWeightedGraph* const InGraph,
	const CHeuristic* const InHeuristic):
	CAction(5.0, 5.0, true),
	WeightedBehaviors(InWeightedBehaviors),
	Path(InPath),
	DivisionScheme(InDivisionScheme),
	ClickTarget(InClickTarget),
	Character(nullptr),
	Monster(nullptr),
	Graph(InGraph),
	Heuristic(InHeuristic)
{
}

//=======================================================================================================================
CFollowAction::~CFollowAction()
{
}

//=======================================================================================================================
void CFollowAction::Execute()
{
	for (auto Behavior : WeightedBehaviors)
	{
		delete Behavior;
	}
	WeightedBehaviors.clear();

	if (Monster)
	{
		WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicPathFollow(Path, DivisionScheme, Character->GetCenterOfMass()), 1));
		WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));

		if (DivisionScheme)
		{
			int StartNode = DivisionScheme->Quantize(Monster->GetCenterOfMass());
			int GoalNode = DivisionScheme->Quantize(Character->GetCenterOfMass());

			Pathfinding::FindPath(StartNode, GoalNode, Graph, Heuristic, Path);
		}
	}
	else
	{
		WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicPathFollow(Path, DivisionScheme, ClickTarget), 1));
		WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));

		if (DivisionScheme)
		{
			int StartNode = DivisionScheme->Quantize(Character->GetCenterOfMass());
			int GoalNode = DivisionScheme->Quantize(ClickTarget);

			Pathfinding::FindPath(StartNode, GoalNode, Graph, Heuristic, Path);
		}
	}

	IsComplete = true;
	QueuedTime = 0.0;

}
