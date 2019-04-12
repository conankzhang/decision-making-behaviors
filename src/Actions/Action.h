#pragma once

//=======================================================================================================================
class CAction
{
public:
	CAction();
	CAction(double InExpiryTIme, double InPriority, bool InCanInterrupt);
	~CAction();

	inline double GetQueuedTime () const { return QueuedTime; }
	inline void SetQueuedTime(double InQueuedTime) { QueuedTime = InQueuedTime; }

	inline bool IsExpired() const { return QueuedTime > ExpiryTime; }

	inline double GetPriority() const { return Priority; }

	inline bool GetCanInterrupt() const { return CanInterrupt; }

	inline bool GetIsComplete() const { return IsComplete; }
	inline void SetIsComplete(bool InIsComplete) { IsComplete = InIsComplete; }

	virtual bool CanDoBoth(CAction* InAction);
	virtual void Execute() {}

protected:
	double QueuedTime;
	double ExpiryTime;
	double Priority;

	bool CanInterrupt;
	bool IsComplete;
};


//=======================================================================================================================
struct SCompareAction
{
	bool operator()(const CAction* const lhs, const CAction* const rhs) const
	{
		return lhs->GetPriority() > rhs->GetPriority();
	}
};
