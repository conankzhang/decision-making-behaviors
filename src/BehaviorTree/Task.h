#pragma once

#include <list>

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
	CTask();
	~CTask();

	EStatus Run(CTick* InTick);

	void Enter(CTick* InTick);
	void Exit(CTick* InTick);
	void Open(CTick* InTick);
	void Close(CTick* InTick);
	EStatus Execute(CTick* InTick);

	inline const std::list<CTask*>& GetChildren() const { return Children; }

private:
	virtual void OnEnter(CTick* InTick) {};
	virtual void OnExit(CTick* InTick) {};
	virtual void OnOpen(CTick* InTick) {};
	virtual void OnClose(CTick* InTick) {};
	virtual EStatus OnExecute(CTick* InTick) { return EStatus::SUCCESS; }

private:
	int TaskId;
	std::list<CTask*> Children;
};
