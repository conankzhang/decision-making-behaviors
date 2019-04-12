#include "Task.h"

#include "Tick.h"
#include "BlackBoard.h"
#include "BehaviorTree.h"

#include "BlackBoardValue.h"

//=======================================================================================================================
CTask::CTask()
{
}

//=======================================================================================================================
CTask::~CTask()
{
}

//=======================================================================================================================
EStatus CTask::Run(CTick* InTick)
{
	Enter(InTick);
	std::shared_ptr<CBlackBoardValueBase> IsOpenValueBase = InTick->GetBlackBoard()->GetValue("IsOpen", InTick->GetBehaviorTree()->GetTreeId(), TaskId);
	bool IsOpenValue = dynamic_cast<CBlackBoardValue<bool>&>(*IsOpenValueBase).GetValue();

	if (!IsOpenValue)
	{
		Open(InTick);
	}

	EStatus eStatus = Execute(InTick);
	if (eStatus != EStatus::RUNNING)
	{
		Close(InTick);
	}

	Exit(InTick);
	return eStatus;
}

//=======================================================================================================================
void CTask::Enter(CTick* InTick)
{
	OnEnter(InTick);
}

//=======================================================================================================================
void CTask::Exit(CTick* InTick)
{
	OnExit(InTick);
}

//=======================================================================================================================
void CTask::Open(CTick* InTick)
{
	OnOpen(InTick);
	InTick->OpenTask(this);
	InTick->GetBlackBoard()->SetValue("IsOpen", new CBlackBoardValue<bool>(true), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
}

//=======================================================================================================================
void CTask::Close(CTick* InTick)
{
	OnClose(InTick);
	InTick->CloseTask(this);
	InTick->GetBlackBoard()->SetValue("IsOpen", new CBlackBoardValue<bool>(false), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
}

//=======================================================================================================================
EStatus CTask::Execute(CTick* InTick)
{
	return OnExecute(InTick);
}
