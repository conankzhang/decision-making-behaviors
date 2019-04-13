#include "Randomizer.h"

#include "../Tick.h"
#include "../BlackBoard.h"
#include "../BlackBoardValue.h"
#include "../BehaviorTree.h"

//=======================================================================================================================
CRandomizer::CRandomizer(size_t InTaskId) :
	CTask(InTaskId)
{

}

//=======================================================================================================================
CRandomizer::~CRandomizer()
{
}

//=======================================================================================================================
void CRandomizer::OnOpen(CTick* InTick)
{
	size_t RandomChildId = rand() % ( GetChildren().size() + 1);
	InTick->GetBlackBoard()->SetValue("RunningChild", new CBlackBoardValue<size_t>(0), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
}

//=======================================================================================================================
EStatus CRandomizer::OnExecute(CTick* InTick)
{
	std::shared_ptr<CBlackBoardValueBase> RunningChildIdBase = InTick->GetBlackBoard()->GetValue("RunningChild", InTick->GetBehaviorTree()->GetTreeId(), TaskId);
	size_t RunningChildId = dynamic_cast<CBlackBoardValue<size_t>&>(*RunningChildIdBase).GetValue();

	CTask* ChildTask = GetChildren()[RunningChildId];
	EStatus ChildStatus = ChildTask->Run(InTick);

	if (ChildStatus != EStatus::SUCCESS)
	{
		if (ChildStatus == EStatus::RUNNING)
		{
			InTick->GetBlackBoard()->SetValue("RunningChild", new CBlackBoardValue<size_t>(RunningChildId), InTick->GetBehaviorTree()->GetTreeId(), TaskId);
		}
	}

	return ChildStatus;
}
