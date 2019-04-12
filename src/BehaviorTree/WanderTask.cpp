#include "WanderTask.h"

#include "Tick.h"
#include "BlackBoard.h"
#include "BlackBoardValue.h"
#include "BehaviorTree.h"

#include "../Actions/WanderAction.h"

//=======================================================================================================================
CWanderTask::CWanderTask(size_t InTaskId, CAction* InAction) :
	CTask(InTaskId),
	Action(InAction)
{

}

//=======================================================================================================================
CWanderTask::~CWanderTask()
{
}

//=======================================================================================================================
EStatus CWanderTask::OnExecute(CTick* InTick)
{
	InTick->GetBlackBoard()->SetValue("Action", new CBlackBoardValue<CAction*>(Action));

	return EStatus::SUCCESS;
}
