#include "BehaviorTree.h"

#include "Tick.h"

#include "BlackBoard.h"
#include "BlackBoardValue.h"

#include "Tasks/Task.h"
#include "../Actions/Action.h"

//=======================================================================================================================
CBehaviorTree::CBehaviorTree(size_t InTreeId, CTask* InRootTask, CBlackBoard* InBlackBoard) :
	TreeId(InTreeId),
	RootTask(InRootTask),
	BlackBoard(InBlackBoard)
{

}

//=======================================================================================================================
CBehaviorTree::~CBehaviorTree()
{
}

//=======================================================================================================================
CAction* CBehaviorTree::GetAction()
{
	CTick* Tick = new CTick(this, BlackBoard);
	RootTask->Run(Tick);

	std::shared_ptr<CBlackBoardValueBase> ActionBase = Tick->GetBlackBoard()->GetValue("Action");
	if (!ActionBase)
	{
		return nullptr;
	}

	return dynamic_cast<CBlackBoardValue<CAction*>&>(*ActionBase).GetValue();
}
