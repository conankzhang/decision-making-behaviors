#include "ActionManager.h"

#include "Action.h"

CActionManager::CActionManager()
{
}


CActionManager::~CActionManager()
{
}

void CActionManager::ScheduleAction(CAction* InAction)
{
	PendingActions.push(InAction);
}

void CActionManager::Update(double InDeltaTime)
{
	std::vector<CAction*> ActionsToRemove;

	// Update Queued Time
	for (auto PendingAction : PendingActions.get_container())
	{
		PendingAction->SetQueuedTime(PendingAction->GetQueuedTime() + InDeltaTime);

		if (PendingAction->IsExpired())
		{
			ActionsToRemove.push_back(PendingAction);
		}
	}

	for (auto PendingAction : ActionsToRemove)
	{
		PendingActions.remove(PendingAction);
	}

	ActionsToRemove.clear();

	// Check for Interrupts
	for (auto PendingAction : PendingActions.get_container())
	{
		CAction* TopPriorityAction = ActiveActions.top();
		if (TopPriorityAction != nullptr && TopPriorityAction->GetPriority() > PendingAction->GetPriority())
		{
			continue;
		}

		if (PendingAction->GetCanInterrupt())
		{
			ActionsToRemove.push_back(PendingAction);

			ActiveActions.get_container().clear();
			ActiveActions.push(PendingAction);
		}
	}

	for (auto PendingAction : ActionsToRemove)
	{
		PendingActions.remove(PendingAction);
	}

	ActionsToRemove.clear();

	// Promote Queued Actions to Active
	std::vector<CAction*> ActionsToAdd;

	for (auto PendingAction : PendingActions.get_container())
	{
		for (auto ActiveAction : ActiveActions.get_container())
		{
			if (!ActiveAction->CanDoBoth(PendingAction))
			{
				continue;
			}

			ActionsToRemove.push_back(PendingAction);
			ActionsToAdd.push_back(PendingAction);
		}
	}

	for (auto PendingAction : ActionsToRemove)
	{
		PendingActions.remove(PendingAction);
	}

	ActionsToRemove.clear();

	for (auto PendingAction : ActionsToAdd)
	{
		ActiveActions.push(PendingAction);
	}

	ActionsToAdd.clear();

	// Run Active Actions
	for (auto ActiveAction : ActiveActions.get_container())
	{
		if (ActiveAction->GetIsComplete())
		{
			ActionsToRemove.push_back(ActiveAction);
		}
		else
		{
			ActiveAction->Execute();
		}
	}

	for (auto ActiveAction : ActionsToRemove)
	{
		ActiveActions.remove(ActiveAction);
	}

	ActionsToRemove.clear();
}
