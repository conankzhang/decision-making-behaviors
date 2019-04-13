#include "DynamicPathFollow.h"

#include "../Pathfinding/DirectedWeightedGraph.h"
#include "../Pathfinding/DivisionScheme.h"
#include "../Entity/Boid.h"
#include "../Entity/Flock.h"

#include <stack>

//=======================================================================================================================
CDynamicPathFollow::CDynamicPathFollow(std::stack<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme, const ofVec2f& InClickTarget) :
	Path(InPath),
	TargetRadius(100.0f),
	DivisionScheme(InDivisionScheme),
	ClickTarget(InClickTarget)

{
}

//=======================================================================================================================
CDynamicPathFollow::~CDynamicPathFollow()
{
}

//=======================================================================================================================
SBehaviorOutput CDynamicPathFollow::GetBehaviorOutput(const CBoid& InBoid)
{
	if (!Path.empty() && DivisionScheme)
	{
		ofVec2f Target = DivisionScheme->Localize(Path.top()->GetSink());
		SeekSteering.SetTarget(Target);

		float Distance = (InBoid.GetPosition() - Target).length();
		if (Distance < TargetRadius)
		{
			Path.pop();

			if (!Path.empty())
			{
				Target = DivisionScheme->Localize(Path.top()->GetSink());
				SeekSteering.SetTarget(Target);
			}
			else
			{
				SeekSteering.SetTarget(ClickTarget);
				InBoid.GetFlock()->SetBehavior(EBehavior::WANDER);
			}
		}
	}

	SBehaviorOutput BehaviorOutput = SeekSteering.GetBehaviorOutput(InBoid);
	BehaviorOutput.Dynamic = false;

	return BehaviorOutput;
}
