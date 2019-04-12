#include "Selector.h"

#include "Tick.h"
#include "BlackBoard.h"
#include "BlackBoardValue.h"
#include "BehaviorTree.h"

//=======================================================================================================================
CSelector::CSelector(size_t InTaskId) :
	CTask(InTaskId)
{

}

//=======================================================================================================================
CSelector::~CSelector()
{
}

//=======================================================================================================================
void CSelector::OnOpen(CTick* InTick)
{
	InTick->GetBlackBoard()->SetValue("RunningChild", new CBlackBoardValue<size_t>(0), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
}

//=======================================================================================================================
EStatus CSelector::OnExecute(CTick* InTick)
{
	std::shared_ptr<CBlackBoardValueBase> RunningChildIdBase = InTick->GetBlackBoard()->GetValue("RunningChild", InTick->GetBehaviorTree()->GetTreeId(), TaskId);
	size_t RunningChildId = dynamic_cast<CBlackBoardValue<size_t>&>(*RunningChildIdBase).GetValue();

	for (size_t ChildId = RunningChildId; ChildId < GetChildren().size(); ChildId++)
	{
		CTask* ChildTask = GetChildren()[ChildId];
		EStatus ChildStatus = ChildTask->Run(InTick);

		if (ChildStatus != EStatus::FAILURE)
		{
			if (ChildStatus == EStatus::RUNNING)
			{
				InTick->GetBlackBoard()->SetValue("RunningChild", new CBlackBoardValue<size_t>(ChildId), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
			}
			return ChildStatus;
		}
	}

	return EStatus::FAILURE;
}
