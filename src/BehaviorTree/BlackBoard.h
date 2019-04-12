#pragma once

#include <unordered_map>
#include <string>

#include "BlackBoardValue.h"

class CBlackBoard
{
public:
	CBlackBoard();
	~CBlackBoard();

	void Set(std::string InKey, const std::shared_ptr<CBlackBoardValueBase> InValue, int InTreeId, int InTaskId);
	std::shared_ptr<CBlackBoardValueBase> Get(std::string InKey, int InTreeId, int InTaskId);

private:
	std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>> test;
};

