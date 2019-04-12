#include "CanSmellCharacterTask.h"

#include "../../Entity/Flock.h"

//=======================================================================================================================
CCanSmellCharacterTask::CCanSmellCharacterTask(size_t InTaskId, CFlock* InCharacter) :
	CTask(InTaskId),
	Character(InCharacter),
	Monster(nullptr)
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
		return EStatus::SUCCESS;
	}

	return EStatus::FAILURE;
}
