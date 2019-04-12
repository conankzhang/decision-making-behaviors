#pragma once

//=======================================================================================================================
class CBlackBoardValueBase
{
public:
	virtual ~CBlackBoardValueBase() = 0;
};

inline CBlackBoardValueBase::~CBlackBoardValueBase() {}

//=======================================================================================================================
template<class T>
class CBlackBoardValue : public CBlackBoardValueBase
{
public:
	explicit CBlackBoardValue(const T& InValue) : Value(InValue) {}

	T GetValue() { return Value; }
	void SetValue(T InValue) { Value = InValue; }

private:
	T Value;
};
