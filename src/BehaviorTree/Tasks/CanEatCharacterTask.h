#pragma once

#include "Task.h"

class CFlock;

//=======================================================================================================================
class CCanEatCharacerTask : public CTask
{
public:
	CCanEatCharacerTask(size_t InTaskId, CFlock* InCharacter);
	~CCanEatCharacerTask();

	inline void SetMonster(CFlock * InMonster) { Monster = InMonster; }

protected:
	virtual EStatus OnExecute(CTick* InTick) override;

protected:
	CFlock* Character;
	CFlock* Monster;

};
