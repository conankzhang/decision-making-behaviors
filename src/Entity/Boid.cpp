#include "Boid.h"

#include "Breadcrumb.h"

#include "ofGraphics.h"
#include "ofAppRunner.h"

//=======================================================================================================================
CBoid::CBoid() :
	Color(ofColor::black),
	Size(10),
	BreadcrumbDropDistance(50),
	LastBreadcrumbPosition(Transform.Position)
{
	Transform.Position.x = Size;
	Transform.Position.y = ofGetWindowHeight() - Size;
}

//=======================================================================================================================
CBoid::CBoid(const SKinematic& InTransform, const ofColor& InColor, float InSize) :
	Transform(InTransform),
	Color(InColor),
	Size(InSize),
	BreadcrumbDropDistance(50),
	LastBreadcrumbPosition(Transform.Position)
{

}

//=======================================================================================================================
CBoid::CBoid(const CBoid& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size),
	BreadcrumbDropDistance(Other.BreadcrumbDropDistance),
	LastBreadcrumbPosition(Other.LastBreadcrumbPosition)
{

}

//=======================================================================================================================
CBoid::CBoid(CBoid&& Other) :
	Transform(Other.Transform),
	Color(Other.Color),
	Size(Other.Size),
	BreadcrumbDropDistance(Other.BreadcrumbDropDistance),
	LastBreadcrumbPosition(Other.LastBreadcrumbPosition)
{

}

//=======================================================================================================================
CBoid& CBoid::operator=(const CBoid& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;
	BreadcrumbDropDistance = Other.BreadcrumbDropDistance;
	LastBreadcrumbPosition = Other.LastBreadcrumbPosition;

	return *this;
}

//=======================================================================================================================
CBoid& CBoid::operator=(CBoid&& Other)
{
	Transform = Other.Transform;
	Color = Other.Color;
	Size = Other.Size;
	BreadcrumbDropDistance = Other.BreadcrumbDropDistance;
	LastBreadcrumbPosition = Other.LastBreadcrumbPosition;

	return *this;
}

//=======================================================================================================================
CBoid::~CBoid()
{
}

//=======================================================================================================================
void CBoid::Update(const SBehaviorOutput& Behavior, double DeltaTime)
{
	Transform.Update(Behavior, DeltaTime);
	UpdateBreadCrumbs(DeltaTime);
	HandleBoundaries();
}

//=======================================================================================================================
void CBoid::Draw(const ofColor& BoidColor) const
{
	ofSetColor(BoidColor);

	ofDrawCircle(Transform.Position, Size);
	DrawBeak();

	for (auto BreadCrumb : BreadCrumbs)
	{
		BreadCrumb->Draw();
	}
}

//=======================================================================================================================
void CBoid::UpdateBreadCrumbs(double DeltaTime)
{
	auto Write = BreadCrumbs.begin();

	for (auto Read = Write, End = BreadCrumbs.end(); Read != End; ++Read)
	{
		if ((*Read)->GetIsAlive())
		{
			if (Read != Write)
			{
				*Write = std::move(*Read);
			}

			++Write;
			(*Read)->Update(DeltaTime);
		}
	}

	BreadCrumbs.erase(Write, BreadCrumbs.end());

	float DistanceToLastBreadCrumb = (Transform.Position - LastBreadcrumbPosition).length();

	if (DistanceToLastBreadCrumb > BreadcrumbDropDistance)
	{
		BreadCrumbs.push_back(new CBreadcrumb(Transform.Position));
		LastBreadcrumbPosition = Transform.Position;
	}
}

//=======================================================================================================================
void CBoid::DrawBeak() const
{
	// Default Beak to the Right Vertices
	ofVec2f TriangleVertex1(0.0f, -Size);
	ofVec2f TriangleVertex2(0.0f, Size);
	ofVec2f TriangleVertex3(Size * 2, 0.0f);

	// Apply Orientation to Vertices
	RotateVertex(TriangleVertex1);
	RotateVertex(TriangleVertex2);
	RotateVertex(TriangleVertex3);

	// Translate Vertices to Position
	TriangleVertex1 += Transform.Position;
	TriangleVertex2 += Transform.Position;
	TriangleVertex3 += Transform.Position;

	ofDrawTriangle(TriangleVertex1, TriangleVertex2, TriangleVertex3);
}

//=======================================================================================================================
void CBoid::RotateVertex(ofVec2f& Vertex) const
{
	float Orientation = Transform.Orientation;

	float X = Vertex.x * cos(Orientation) - Vertex.y * sin(Orientation);
	float Y = Vertex.x * sin(Orientation) + Vertex.y * cos(Orientation);

	Vertex.x = X;
	Vertex.y = Y;
}

void CBoid::HandleBoundaries()
{
	if (Transform.Position.x < 0 || Transform.Position.x > ofGetWindowWidth())
	{
		Transform.Velocity.x *= -1;
	}

	if (Transform.Position.y < 0 || Transform.Position.y > ofGetWindowHeight())
	{
		Transform.Velocity.y *= -1;
	}
}
