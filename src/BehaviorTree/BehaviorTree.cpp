#include "BehaviorTree.h"

#include "Tick.h"
#include "Task.h"

#include "BlackBoard.h"
#include "BlackBoardValue.h"

#include "../Actions/Action.h"

//=======================================================================================================================
CBehaviorTree::CBehaviorTree(int InTreeId, CTask* InRoot, CBlackBoard* InBlackBoard) :
	TreeId(InTreeId),
	Root(InRoot),
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
	Root->Run(Tick);

	std::shared_ptr<CBlackBoardValueBase> ActionBase = Tick->GetBlackBoard()->GetValue("Action");
	return dynamic_cast<CBlackBoardValue<CAction*>&>(*ActionBase).GetValue();
}
