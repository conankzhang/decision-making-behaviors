#include "FollowAction.h"

#include "../Behavior/DynamicLookWhereYouAreGoing.h"
#include "../Behavior/DynamicPathFollow.h"

//=======================================================================================================================
CFollowAction::CFollowAction(std::vector<SWeightedBehavior>& InWeightedBehaviors, std::stack<const CDirectedWeightedEdge*>& InPath, CDivisionScheme* InDivisionScheme, const ofVec2f& InClickTarget) :
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
	WeightedBehaviors.clear();

	WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicPathFollow(Path, DivisionScheme, ClickTarget), 1));
	WeightedBehaviors.push_back(SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));

	IsComplete = true;
}
