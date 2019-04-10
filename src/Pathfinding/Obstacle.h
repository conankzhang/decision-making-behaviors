#pragma once

#include "ofVec2f.h"

class CObstacle
{
public:
	CObstacle(float InXPosition, float InYPosition, float InWidth, float InHeight);
	~CObstacle();

	void Draw();

	bool IsInObstacle(const ofVec2f& InPosition);

private:
	float XPosition;
	float YPosition;

	float Width;
	float Height;
};

