#include "DynamicAlign.h"

#include "../Entity/Boid.h"

//=======================================================================================================================
CDynamicAlign::CDynamicAlign() :
	TargetAngleThreshold(0.1f),
	SlowAngleThreshold(0.3f),
	TimeToTarget(1.0f),
	MaxRotation(10.0f),
	MaxAngularAcceleration(10.0f),
	TargetOrientation(0.0f)
{

}

//=======================================================================================================================
CDynamicAlign::~CDynamicAlign()
{

}

//=======================================================================================================================
SBehaviorOutput CDynamicAlign::GetBehaviorOutput(const CBoid& InBoid)
{
	SBehaviorOutput BehaviorOutput;

	float Rotation = TargetOrientation - InBoid.GetOrientation();

	Rotation = MapToRange(Rotation);
	float RotationSize = abs(Rotation);
	float TargetRotation = 0.0f;
	if (RotationSize < TargetAngleThreshold)
	{
		return BehaviorOutput;
	}

	if (RotationSize > SlowAngleThreshold)
	{
		TargetRotation = MaxRotation;
	}
	else
	{
		TargetRotation = MaxRotation * RotationSize / SlowAngleThreshold;
	}

	// Calculate Sign of TargetRotation
	TargetRotation *= Rotation / RotationSize;

	float DeltaVelocity = TargetRotation - InBoid.GetRotation();
	float Acceleration = DeltaVelocity / TimeToTarget;

	if (Acceleration > MaxAngularAcceleration)
	{
		Acceleration = MaxAngularAcceleration;
	}

	BehaviorOutput.Angular = Acceleration;

	return BehaviorOutput;
}

//=======================================================================================================================
float CDynamicAlign::MapToRange(float InRotation)
{
	float Rotation = InRotation;

	while (Rotation > PI)
	{
		Rotation -= 2 * PI;
	}

	while (Rotation < -PI)
	{
		Rotation += 2 * PI;
	}

	return Rotation;
}
