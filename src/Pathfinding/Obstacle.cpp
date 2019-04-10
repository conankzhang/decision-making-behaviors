#include "Obstacle.h"

#include "ofGraphics.h"

//=======================================================================================================================
CObstacle::CObstacle(float InXPosition, float InYPosition, float InWidth, float InHeight) :
	XPosition(InXPosition),
	YPosition(InYPosition),
	Width(InWidth),
	Height(InHeight)
{

}

//=======================================================================================================================
CObstacle::~CObstacle()
{
}

//=======================================================================================================================
void CObstacle::Draw()
{
	ofSetColor(ofColor::black);
	ofDrawRectangle(XPosition, YPosition, Width, Height);
}

//=======================================================================================================================
bool CObstacle::IsInObstacle(const ofVec2f& InPosition)
{
	bool InHorizontally = InPosition.x < XPosition + Width && InPosition.x > XPosition;
	bool InVertically = InPosition.y < YPosition + Height && InPosition.y > YPosition;

	return InHorizontally && InVertically;
}
