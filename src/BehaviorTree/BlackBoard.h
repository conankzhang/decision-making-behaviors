#pragma once

#include <unordered_map>
#include <string>

#include "BlackBoardValue.h"

//=======================================================================================================================
class CBlackBoard
{
public:
	CBlackBoard();
	~CBlackBoard();

	void SetValue(std::string InKey, const std::shared_ptr<CBlackBoardValueBase> InValue, int InTreeId, int InTaskId);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey, int InTreeId, int InTaskId);

private:
	std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>> test;
};
