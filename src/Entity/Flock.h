#pragma once

#include "../Behavior/Behavior.h"

#include "ofColor.h"

#include <vector>

class CBoid;

//=======================================================================================================================
class CFlock
{
public:
	CFlock(int InFlockCount, const std::vector<SWeightedBehavior>& InWeightedBehaviors, const ofColor& InColor);
	~CFlock();

	void Update(float DeltaTime);
	void Draw() const;

	const std::vector<CBoid *>* GetBoids() const { return &Boids; }
	const ofVec2f& GetCenterOfMass() const { return CenterOfMass; }

private:
	const ofColor& FlockColor;
	void UpdateCenterOfMass();
	SBehaviorOutput GetBehaviorOutput(const CBoid& InBoid);

	ofVec2f CenterOfMass;

	std::vector<CBoid *> Boids;
	const std::vector<SWeightedBehavior>& WeightedBehaviors;
};
