#pragma once

#include <unordered_map>
#include <string>
#include <vector>

#include "BlackBoardValue.h"

//=======================================================================================================================
class CBlackBoard
{
public:
	CBlackBoard();
	~CBlackBoard();

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue, int InTreeId, int InTaskId);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey, int InTreeId, int InTaskId);

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue, int InTreeId);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey, int InTreeId);

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey);

private:
	std::vector<std::vector<std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>>>> NodeMap;
	std::vector<std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>>> TreeMap;
	std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>> GlobalMap;
};
