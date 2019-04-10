#pragma once

class CDivisionScheme;

//=======================================================================================================================
class CHeuristic
{
public:
	CHeuristic(CDivisionScheme* InDivisionScheme);
	virtual ~CHeuristic();

	virtual float GetEstimate(int CurrentNode, int GoalNode) const { return 0; }

protected:
	CDivisionScheme* DivisionScheme;
};

//=======================================================================================================================
class CZeroEstimate : public CHeuristic
{
public:
	CZeroEstimate(CDivisionScheme* InDivisionScheme);
	~CZeroEstimate();
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};

//=======================================================================================================================
class CRandomEstimate : public CHeuristic
{
public:
	CRandomEstimate(CDivisionScheme* InDivisionScheme);
	~CRandomEstimate();

	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};

//=======================================================================================================================
class CEuclideanDistance : public CHeuristic
{
public:
	CEuclideanDistance(CDivisionScheme* InDivisionScheme);
	~CEuclideanDistance();
	virtual float GetEstimate(int CurrentNode, int GoalNode) const override;
};
