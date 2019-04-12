#include "Inverter.h"

//=======================================================================================================================
CInverter::CInverter(size_t InTaskId) :
	CTask(InTaskId)
{
}

//=======================================================================================================================
CInverter::~CInverter()
{
}

//=======================================================================================================================
EStatus CInverter::OnExecute(CTick* InTick)
{
	EStatus ChildStatus = GetChildren()[0]->Run(InTick);
	if (ChildStatus == EStatus::SUCCESS)
	{
		return EStatus::FAILURE;
	}
	if (ChildStatus == EStatus::FAILURE)
	{
		return EStatus::SUCCESS;
	}

	return ChildStatus;
}
