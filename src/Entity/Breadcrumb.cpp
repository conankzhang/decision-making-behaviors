#include "Breadcrumb.h"

#include "ofGraphics.h"

//=======================================================================================================================
CBreadcrumb::CBreadcrumb(const ofVec2f& InPosition) :
	Position(InPosition),
	Color(ofColor::black),
	LifeSpan(3),
	OriginalLifeSpan(3),
	Size(3),
	OriginalSize(3),
	IsAlive(true)
{
}

//=======================================================================================================================
CBreadcrumb::CBreadcrumb(const CBreadcrumb& Other) :
	Position(Other.Position),
	Color(Other.Color),
	LifeSpan(Other.LifeSpan),
	OriginalLifeSpan(Other.OriginalLifeSpan),
	Size(Other.Size),
	OriginalSize(Other.OriginalSize),
	IsAlive(Other.IsAlive)
{

}

//=======================================================================================================================
CBreadcrumb::CBreadcrumb(CBreadcrumb&& Other) :
	Position(Other.Position),
	Color(Other.Color),
	LifeSpan(Other.LifeSpan),
	OriginalLifeSpan(Other.OriginalLifeSpan),
	Size(Other.Size),
	OriginalSize(Other.OriginalSize),
	IsAlive(Other.IsAlive)
{

}

//=======================================================================================================================
CBreadcrumb& CBreadcrumb::operator=(const CBreadcrumb& Other)
{
	Position = Other.Position;
	Color = Other.Color;
	LifeSpan = Other.LifeSpan;
	OriginalLifeSpan = Other.OriginalLifeSpan;
	Size = Other.Size;
	OriginalSize = Other.OriginalSize;
	IsAlive = Other.IsAlive;

	return *this;
}

//=======================================================================================================================
CBreadcrumb& CBreadcrumb::operator=(CBreadcrumb&& Other)
{
	Position = Other.Position;
	Color = Other.Color;
	LifeSpan = Other.LifeSpan;
	OriginalLifeSpan = Other.OriginalLifeSpan;
	Size = Other.Size;
	OriginalSize = Other.OriginalSize;
	IsAlive = Other.IsAlive;

	return *this;
}

//=======================================================================================================================
CBreadcrumb::~CBreadcrumb()
{
}

//=======================================================================================================================
void CBreadcrumb::Update(double DeltaTime)
{
	LifeSpan -= DeltaTime;
	if (LifeSpan < 0)
	{
		IsAlive = false;
	}
	Size = (OriginalSize * (LifeSpan / OriginalLifeSpan));
}

//=======================================================================================================================
void CBreadcrumb::Draw() const
{
	ofSetColor(Color);

	ofDrawCircle(Position, Size);
}
