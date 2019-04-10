#pragma once

#include <vector>
#include <stack>

class CDirectedWeightedEdge;
class CDirectedWeightedGraph;

class CHeuristic;

//=======================================================================================================================
namespace Pathfinding
{
	struct SNodeRecord
	{
		SNodeRecord();
		SNodeRecord(int InNode, const CDirectedWeightedEdge* InEdge, float InCost, float InEstimatedCost);

		int Node;

		const CDirectedWeightedEdge* IncomingEdge;

		float CostSoFar;
		float EstimatedTotalCost;
	};

	struct SCompareNodeRecord
	{
		bool operator()(const SNodeRecord* const lhs, const SNodeRecord* const rhs) const
		{
			return lhs->EstimatedTotalCost > rhs->EstimatedTotalCost;
		}
	};

	bool FindPath(int StartNode, int GoalNode, const CDirectedWeightedGraph* const Graph, const CHeuristic* const Heuristic, std::stack<const CDirectedWeightedEdge*>& OutPath);
};
