#include "Action.h"

//=======================================================================================================================
CAction::CAction() :
	QueuedTime(0.0f),
	ExpiryTime(0.0f),
	Priority(0.0f),
	CanInterrupt(false),
	IsComplete(false)
{

}

//=======================================================================================================================
CAction::CAction(double InExpiryTIme, double InPriority, bool InCanInterrupt) :
	QueuedTime(0.0f),
	ExpiryTime(InExpiryTIme),
	Priority(InPriority),
	CanInterrupt(InCanInterrupt),
	IsComplete(false)
{

}

//=======================================================================================================================
CAction::~CAction()
{

}

//=======================================================================================================================
bool CAction::CanDoBoth(CAction* InAction)
{
	return false;
}
