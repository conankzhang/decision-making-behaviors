#include "ActionTask.h"

#include "../Tick.h"
#include "../BlackBoard.h"
#include "../BlackBoardValue.h"
#include "../BehaviorTree.h"

#include "../../Actions/WanderAction.h"

//=======================================================================================================================
CActionTask::CActionTask(size_t InTaskId, CAction* InAction) :
	CTask(InTaskId),
	Action(InAction)
{

}

//=======================================================================================================================
CActionTask::~CActionTask()
{
}

//=======================================================================================================================
EStatus CActionTask::OnExecute(CTick* InTick)
{
	InTick->GetBlackBoard()->SetValue("Action", new CBlackBoardValue<CAction*>(Action));

	return EStatus::SUCCESS;
}
