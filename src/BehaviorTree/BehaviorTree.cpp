#include "BehaviorTree.h"

#include "Tick.h"
#include "Task.h"

#include "BlackBoard.h"
#include "BlackBoardValue.h"

#include "../Actions/Action.h"

//=======================================================================================================================
CBehaviorTree::CBehaviorTree(int InTreeId, CTask* InRootTask, CBlackBoard* InBlackBoard) :
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
	return dynamic_cast<CBlackBoardValue<CAction*>&>(*ActionBase).GetValue();
}
