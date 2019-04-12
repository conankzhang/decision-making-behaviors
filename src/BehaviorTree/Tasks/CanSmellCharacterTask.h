#pragma once

#include "Task.h"

class CFlock;

//=======================================================================================================================
class CCanSmellCharacterTask : public CTask
{
public:
	CCanSmellCharacterTask(size_t InTaskId, CFlock* InCharacter);
	~CCanSmellCharacterTask();

	inline void SetMonster(CFlock * InMonster) { Monster = InMonster; }

protected:
	virtual EStatus OnExecute(CTick* InTick) override;

protected:
	CFlock* Character;
	CFlock* Monster;
};
