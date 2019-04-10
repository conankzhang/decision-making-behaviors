#include "Heuristic.h"

#include "DivisionScheme.h"

//=======================================================================================================================
CHeuristic::CHeuristic(CDivisionScheme* InDivisionScheme) :
	DivisionScheme(InDivisionScheme)
{

}

//=======================================================================================================================
CHeuristic::~CHeuristic()
{
	if (DivisionScheme)
	{
		delete DivisionScheme;
		DivisionScheme = nullptr;
	}
}

//=======================================================================================================================
CZeroEstimate::CZeroEstimate(CDivisionScheme* InDivisionScheme) :
	CHeuristic(InDivisionScheme)
{

}

//=======================================================================================================================
CZeroEstimate::~CZeroEstimate()
{
	if (DivisionScheme)
	{
		delete DivisionScheme;
		DivisionScheme = nullptr;
	}
}

//=======================================================================================================================
float CZeroEstimate::GetEstimate(int CurrentNode, int GoalNode) const
{
	return 0;
}

//=======================================================================================================================
CRandomEstimate::CRandomEstimate(CDivisionScheme* InDivisionScheme) :
	CHeuristic(InDivisionScheme)
{

}

//=======================================================================================================================
CRandomEstimate::~CRandomEstimate()
{
	if (DivisionScheme)
	{
		delete DivisionScheme;
		DivisionScheme = nullptr;
	}
}

//=======================================================================================================================
float CRandomEstimate::GetEstimate(int CurrentNode, int GoalNode) const
{
	return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/16));
}

//=======================================================================================================================
CEuclideanDistance::CEuclideanDistance(CDivisionScheme* InDivisionScheme) :
	CHeuristic(InDivisionScheme)
{

}

//=======================================================================================================================
CEuclideanDistance::~CEuclideanDistance()
{
	if (DivisionScheme)
	{
		delete DivisionScheme;
		DivisionScheme = nullptr;
	}
}

//=======================================================================================================================
float CEuclideanDistance::GetEstimate(int CurrentNode, int GoalNode) const
{
	if (!DivisionScheme)
	{
		return 0;
	}

	ofVec2f CurrentPosition = DivisionScheme->Localize(CurrentNode);
	ofVec2f GoalPosition = DivisionScheme->Localize(GoalNode);

	return (CurrentPosition - GoalPosition).length();
}
