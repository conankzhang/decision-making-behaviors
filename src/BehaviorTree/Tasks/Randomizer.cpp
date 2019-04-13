#include "Randomizer.h"

#include "../Tick.h"
#include "../BlackBoard.h"
#include "../BlackBoardValue.h"
#include "../BehaviorTree.h"

//=======================================================================================================================
CRandomizer::CRandomizer(size_t InTaskId) :
	CTask(InTaskId),
	RandomChildId(0)
{

}

//=======================================================================================================================
CRandomizer::~CRandomizer()
{
}

//=======================================================================================================================
void CRandomizer::OnOpen(CTick* InTick)
{
	std::shared_ptr<CBlackBoardValueBase> RandomizeBase = InTick->GetBlackBoard()->GetValue("Randomize");

	bool bRandomize = false;
	if (RandomizeBase)
	{
		bRandomize = dynamic_cast<CBlackBoardValue<bool>&>(*RandomizeBase).GetValue();
	}

	if (bRandomize)
	{
		RandomChildId = rand() % 2;
		InTick->GetBlackBoard()->SetValue("Randomize", new CBlackBoardValue<bool>(false));
	}
}

//=======================================================================================================================
EStatus CRandomizer::OnExecute(CTick* InTick)
{
	CTask* ChildTask = GetChildren()[RandomChildId];
	EStatus ChildStatus = ChildTask->Run(InTick);

	return ChildStatus;
}
