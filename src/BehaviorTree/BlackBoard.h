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

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue, size_t InTreeId, size_t InTaskId);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey, size_t InTreeId, size_t InTaskId);

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue, size_t InTreeId);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey, size_t InTreeId);

	void SetValue(std::string InKey, CBlackBoardValueBase* InValue);
	std::shared_ptr<CBlackBoardValueBase> GetValue(std::string InKey);

private:
	std::unordered_map<size_t, std::unordered_map<size_t, std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>>>> NodeMap;
	std::unordered_map<size_t, std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>>> TreeMap;
	std::unordered_map<std::string, std::shared_ptr<CBlackBoardValueBase>> GlobalMap;
};
