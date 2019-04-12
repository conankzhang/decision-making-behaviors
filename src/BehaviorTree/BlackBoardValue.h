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

	const T& GetValue() const { return Value; }
	void SetValue(const T& InValue) { Value = InValue; }

private:
	T Value;
};
