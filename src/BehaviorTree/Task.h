#pragma once

#include <vector>

class CTick;

//=======================================================================================================================
enum class EStatus
{
	SUCCESS,
	FAILURE,
	RUNNING,
	ERROR
};


//=======================================================================================================================
class CTask
{
public:
	CTask(int InTaskId);
	~CTask();

	EStatus Run(CTick* InTick);

	void Enter(CTick* InTick);
	void Exit(CTick* InTick);
	void Open(CTick* InTick);
	void Close(CTick* InTick);
	EStatus Execute(CTick* InTick);

	inline const std::vector<CTask*>& GetChildren() const { return Children; }

protected:
	virtual void OnEnter(CTick* InTick) {};
	virtual void OnExit(CTick* InTick) {};
	virtual void OnOpen(CTick* InTick) {};
	virtual void OnClose(CTick* InTick) {};
	virtual EStatus OnExecute(CTick* InTick) { return EStatus::SUCCESS; }

protected:
	int TaskId;
	std::vector<CTask*> Children;
};
