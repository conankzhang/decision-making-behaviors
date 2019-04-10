#include "Pathfinding.h"
#include "Heuristic.h"
#include "DirectedWeightedGraph.h"

#include <map>
#include <stack>
#include <queue>

//=======================================================================================================================
Pathfinding::SNodeRecord::SNodeRecord() :
	Node(-1),
	IncomingEdge(nullptr),
	CostSoFar(-1),
	EstimatedTotalCost(-1)
{

}

//=======================================================================================================================
Pathfinding::SNodeRecord::SNodeRecord(int InNode, const CDirectedWeightedEdge* InEdge, float InCost, float InEstimatedCost) :
	Node(InNode),
	IncomingEdge(InEdge),
	CostSoFar(InCost),
	EstimatedTotalCost(InEstimatedCost)
{

}

//=======================================================================================================================
bool Pathfinding::FindPath(int StartNode, int GoalNode, const CDirectedWeightedGraph* const Graph, const CHeuristic* const Heuristic, std::stack<const CDirectedWeightedEdge*>& OutPath)
{
	if (!Heuristic || !Graph)
	{
		return false;
	}

	SNodeRecord* StartRecord = new SNodeRecord(StartNode, nullptr, 0, Heuristic->GetEstimate(StartNode, GoalNode));

	std::map<int, SNodeRecord*> ClosedList;

	std::map<int, SNodeRecord*> OpenNodes;
	std::priority_queue<SNodeRecord*, std::vector<SNodeRecord*>, SCompareNodeRecord> OpenList;

	OpenList.push(StartRecord);
	OpenNodes.insert({ StartRecord->Node, StartRecord });

	SNodeRecord* CurrentRecord;
	while (!OpenList.empty())
	{
		CurrentRecord = OpenList.top();
		OpenList.pop();
		OpenNodes.erase(CurrentRecord->Node);

		if (CurrentRecord)
		{
			if (CurrentRecord->Node == GoalNode)
			{
				break;
			}

			std::vector<const CDirectedWeightedEdge*> OutgoingEdges;
			Graph->GetOutgoingEdges(CurrentRecord->Node, OutgoingEdges);

			int EndNode;
			for (const CDirectedWeightedEdge* Edge : OutgoingEdges)
			{
				if (Edge)
				{
					EndNode = Edge->GetSink();

					float CostSoFar = CurrentRecord->CostSoFar + Edge->GetCost();
					float EstimatedCost = Heuristic->GetEstimate(EndNode, GoalNode);

					SNodeRecord* EndNodeRecord;
					if (ClosedList.count(EndNode) > 0)
					{
						EndNodeRecord = ClosedList.at(EndNode);
						if (EndNodeRecord->CostSoFar <= CostSoFar)
						{
							continue;
						}
						ClosedList.erase(EndNode);
					}

					if (OpenNodes.count(EndNode) > 0)
					{
						EndNodeRecord = OpenNodes.at(EndNode);
						if (EndNodeRecord && EndNodeRecord->CostSoFar <= CostSoFar)
						{
							continue;
						}

						EndNodeRecord->CostSoFar = CostSoFar;
						EndNodeRecord->EstimatedTotalCost = CostSoFar + EstimatedCost;

						// Update priority queue hack
						SNodeRecord* UpdateNodeRecord = new SNodeRecord(-1, nullptr, -1, -1);
						OpenList.push(UpdateNodeRecord);
						OpenList.pop();
					}
					else
					{
						EndNodeRecord = new SNodeRecord(EndNode, Edge, CostSoFar, CostSoFar + EstimatedCost);
						// Hack to avoid obstacles
						if (EndNodeRecord->EstimatedTotalCost >= 100000)
						{
							continue;
						}
						OpenList.push(EndNodeRecord);
						OpenNodes.insert({ EndNodeRecord->Node, EndNodeRecord});
					}
				}
			}

			ClosedList.insert({ CurrentRecord->Node, CurrentRecord});
		}
	}

	if (CurrentRecord)
	{
		if (CurrentRecord->Node != GoalNode)
		{
			return false;
		}

		OutPath = std::stack<const CDirectedWeightedEdge*>();

		while (CurrentRecord->Node != StartNode)
		{
			OutPath.push(CurrentRecord->IncomingEdge);
			CurrentRecord = ClosedList.at(CurrentRecord->IncomingEdge->GetSource());
		}

		return true;
	}

	return false;
}
