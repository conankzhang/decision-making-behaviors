#include "BlackBoard.h"

//=======================================================================================================================
CBlackBoard::CBlackBoard()
{
}

//=======================================================================================================================
CBlackBoard::~CBlackBoard()
{
}

//=======================================================================================================================
void CBlackBoard::SetValue(std::string InKey, CBlackBoardValueBase* InValue, int InTreeId, int InTaskId)
{
	NodeMap[InTreeId][InTaskId][InKey].reset(InValue);
}

//=======================================================================================================================
void CBlackBoard::SetValue(std::string InKey, CBlackBoardValueBase* InValue, int InTreeId)
{
	TreeMap[InTreeId][InKey].reset(InValue);
}

//=======================================================================================================================
void CBlackBoard::SetValue(std::string InKey, CBlackBoardValueBase* InValue)
{
	GlobalMap[InKey].reset(InValue);
}

//=======================================================================================================================
std::shared_ptr<CBlackBoardValueBase> CBlackBoard::GetValue(std::string InKey, int InTreeId, int InTaskId)
{
	return NodeMap[InTreeId][InTaskId][InKey];
}

//=======================================================================================================================
std::shared_ptr<CBlackBoardValueBase> CBlackBoard::GetValue(std::string InKey, int InTreeId)
{
	return TreeMap[InTreeId][InKey];
}

//=======================================================================================================================
std::shared_ptr<CBlackBoardValueBase> CBlackBoard::GetValue(std::string InKey)
{
	return GlobalMap[InKey];
}
