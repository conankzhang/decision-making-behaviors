#include "ofApp.h"
#include "Entity/Flock.h"

#include "Behavior/basic-motion.h"
#include "Behavior/seek-steering.h"
#include "Behavior/DynamicLookWhereYouAreGoing.h"
#include "Behavior/DynamicFace.h"
#include "Behavior/wander-steering.h"
#include "Behavior/DynamicSeparation.h"
#include "Behavior/DynamicPathFollow.h"

#include "Pathfinding/DirectedWeightedGraph.h"
#include "Pathfinding/Pathfinding.h"
#include "Pathfinding/Heuristic.h"
#include "Pathfinding/TiledDivisionScheme.h"
#include "Pathfinding/Obstacle.h"

//=======================================================================================================================
void ofApp::setup()
{
	ofBackground(ofColor::white);
	ofSetCircleResolution(50);

	CreateObstacles();

	Target.x = 0.0f;
	Target.y = ofGetWindowHeight();

	TargetSize = 10.0f;

	Graph = new CDirectedWeightedGraph(EGraph::TILED, ofGetWindowWidth(), ofGetWindowHeight(), 100, 100, Obstacles);
	DivisionScheme = new CTiledDivisionScheme(ofGetWindowWidth(), ofGetWindowHeight(), 100.0f, 100.0f, Graph);
	Heuristic = new CZeroEstimate(DivisionScheme);

	Flock = new CFlock(1, FlockBehaviors, ofColor::black);
	FlockBehaviors.push_back(SWeightedBehavior(new CDynamicPathFollow(Path, DivisionScheme, Target), 1));
	FlockBehaviors.push_back(SWeightedBehavior(new CDynamicLookWhereYouAreGoing(), 1));
}

//=======================================================================================================================
void ofApp::update()
{
	if (Flock)
	{
		Flock->Update(ofGetLastFrameTime());
	}
}

//=======================================================================================================================
void ofApp::draw()
{
	ofSetColor(ofColor::black);

	ofDrawBitmapString("Click anywhere to start pathfinding.", 50, 50);

	ofDrawRectangle(Target.x, Target.y, TargetSize, TargetSize);

	for (auto Obstacle : Obstacles)
	{
		if (Obstacle)
		{
			Obstacle->Draw();
		}
	}

	if (Flock)
	{
		Flock->Draw();
	}
}

//=======================================================================================================================
void ofApp::keyPressed(int key)
{

}

//=======================================================================================================================
void ofApp::mousePressed(int x, int y, int button)
{
	ofVec2f ClickPosition;
	ClickPosition.x = x;
	ClickPosition.y = y;

	for (auto Obstacle : Obstacles)
	{
		if (Obstacle->IsInObstacle(ClickPosition))
		{
			return;
		}
	}

	Target = ClickPosition;

	if (DivisionScheme && Flock)
	{
		int StartNode = DivisionScheme->Quantize(Flock->GetCenterOfMass());
		int GoalNode = DivisionScheme->Quantize(Target);

		Pathfinding::FindPath(StartNode, GoalNode, Graph, Heuristic, Path);
	}
}

//=======================================================================================================================
void ofApp::CreateObstacles()
{
	Obstacles.push_back(new CObstacle(100.0f, 100.0f, 100.0f, 100.0f));
	Obstacles.push_back(new CObstacle(300.0f, 300.0f, 100.0f, 500.0f));
	Obstacles.push_back(new CObstacle(700.0f, 500.0f, 300.0f, 100.0f));
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
