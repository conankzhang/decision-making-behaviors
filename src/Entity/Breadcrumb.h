#pragma once

#include "ofColor.h"
#include "ofVec2f.h"

//=======================================================================================================================
class CBreadcrumb
{
public:
	CBreadcrumb(const ofVec2f& InPosition);
	CBreadcrumb(const CBreadcrumb& Other);
	CBreadcrumb(CBreadcrumb&& Other);
	CBreadcrumb& operator=(const CBreadcrumb& Other);
	CBreadcrumb& operator=(CBreadcrumb&& Other);
	~CBreadcrumb();

	void Update(double DeltaTime);
	void Draw() const;

	inline bool GetIsAlive() { return IsAlive; }

private:
	ofVec2f Position;
	ofColor Color;

	double OriginalLifeSpan;
	double LifeSpan;
	float OriginalSize;
	float Size;

	bool IsAlive;
};

