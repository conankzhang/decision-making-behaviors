#pragma once

//=======================================================================================================================
class CAction
{
public:
	CAction();
	~CAction();

	inline double GetQueuedTime () const { return QueuedTime; }
	inline void SetQueuedTime(double InQueuedTime) { QueuedTime = InQueuedTime; }

	inline bool IsExpired() const { return QueuedTime > ExpiryTime; }

	inline double GetPriority() const { return Priority; }

	inline bool GetCanInterrupt() const { return CanInterrupt; }
	inline bool GetIsComplete() const { return IsComplete; }

	virtual bool CanDoBoth(CAction* InAction) = 0;
	virtual void Execute() = 0;

private:
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