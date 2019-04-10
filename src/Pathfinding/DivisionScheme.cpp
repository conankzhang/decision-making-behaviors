#include "DivisionScheme.h"

#include "DirectedWeightedGraph.h"

bool CDivisionScheme::GetWaypointPath(const std::vector<const CDirectedWeightedEdge*>& Path, std::vector<ofVec2f>& OutWaypoints) const
{
	for (std::vector<const CDirectedWeightedEdge*>::const_reverse_iterator Edge = Path.rbegin(); Edge != Path.rend(); ++Edge )
	{
		if (!(*Edge))
		{
			return false;
		}

		OutWaypoints.push_back(Localize((*Edge)->GetSource()));
	}

	return true;
}
