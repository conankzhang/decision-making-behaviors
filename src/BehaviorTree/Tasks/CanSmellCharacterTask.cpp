#include "CanSmellCharacterTask.h"

#include "../../Entity/Flock.h"
#include "../Tick.h"
#include "../BlackBoard.h"
#include "../BehaviorTree.h"

#include "../BlackBoardValue.h"

//=======================================================================================================================
CCanSmellCharacterTask::CCanSmellCharacterTask(size_t InTaskId, CFlock* InCharacter) :
	CTask(InTaskId),
	Character(InCharacter),
	Monster(nullptr),
	bFound(false)
{

}

//=======================================================================================================================
CCanSmellCharacterTask::~CCanSmellCharacterTask()
{
}

//=======================================================================================================================
EStatus CCanSmellCharacterTask::OnExecute(CTick* InTick)
{
	if (!Character || !Monster)
	{
		return EStatus::FAILURE;
	}

	float Distance = (Character->GetCenterOfMass() - Monster->GetCenterOfMass()).length();

	if (fabsf(Distance) < 250)
	{
		bFound = true;
		return EStatus::SUCCESS;
	}

	if (bFound)
	{
		InTick->GetBlackBoard()->SetValue("Randomize", new CBlackBoardValue<bool>(true));
		bFound = false;
	}

	return EStatus::FAILURE;
}
