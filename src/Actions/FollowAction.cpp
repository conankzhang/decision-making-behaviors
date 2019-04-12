#include "FollowAction.h"

#include "../Movement/DynamicLookWhereYouAreGoing.h"
#include "../Movement/DynamicPathFollow.h"

//=======================================================================================================================
CFollowAction::CFollowAction(std::vector<SWeightedBehavior*>& InWeightedBehaviors, std::stack<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme, const ofVec2f& InClickTarget) :
	CAction(5.0, 5.0, true),
	WeightedBehaviors(InWeightedBehaviors),
	Path(InPath),
	DivisionScheme(InDivisionScheme),
	ClickTarget(InClickTarget)
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

	WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicPathFollow(Path, DivisionScheme, ClickTarget), 1));
	WeightedBehaviors.push_back(new SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));

	IsComplete = true;
	QueuedTime = 0.0;

}
