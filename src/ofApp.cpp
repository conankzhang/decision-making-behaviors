#include "ofApp.h"
#include "Entity/Flock.h"

#include "Movement/basic-motion.h"
#include "Movement/seek-steering.h"
#include "Movement/DynamicLookWhereYouAreGoing.h"
#include "Movement/DynamicFace.h"
#include "Movement/wander-steering.h"
#include "Movement/DynamicSeparation.h"
#include "Movement/DynamicPathFollow.h"

#include "Pathfinding/DirectedWeightedGraph.h"
#include "Pathfinding/Pathfinding.h"
#include "Pathfinding/Heuristic.h"
#include "Pathfinding/TiledDivisionScheme.h"
#include "Pathfinding/Obstacle.h"

#include "DecisionMaking/DecisionMakingBehavior.h"
#include "DecisionMaking/Nodes/FollowWanderDecisionNode.h"
#include "DecisionMaking/ActionNode.h"

#include "Actions/FollowAction.h"
#include "Actions/WanderAction.h"
#include "Actions/ResetAction.h"
#include "Actions/PatrolAction.h"

#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackBoard.h"
#include "BehaviorTree/Tasks/Sequencer.h"
#include "BehaviorTree/Tasks/Selector.h"
#include "BehaviorTree/Tasks/Randomizer.h"
#include "BehaviorTree/Tasks/ActionTask.h"
#include "BehaviorTree/Tasks/CanSmellCharacterTask.h"
#include "BehaviorTree/Tasks/CanEatCharacterTask.h"

//=======================================================================================================================
void ofApp::setup()
{
	ofBackground(ofColor::white);
	ofSetCircleResolution(50);

	CreateObstacles();

	Target.x = 0.0f;
	Target.y = 0.0f;

	TargetSize = 10.0f;

	Graph = new CDirectedWeightedGraph(EGraph::TILED, ofGetWindowWidth(), ofGetWindowHeight(), 100, 100, Obstacles);
	DivisionScheme = new CTiledDivisionScheme(ofGetWindowWidth(), ofGetWindowHeight(), 100.0f, 100.0f, Graph);
	Heuristic = new CZeroEstimate(DivisionScheme);

	CFollowAction* CharacterFollowAction = new CFollowAction(CharacterBehaviors, CharacterPath, DivisionScheme, Target, Graph, Heuristic);
	CActionNode* FollowActionNode = new CActionNode(CharacterFollowAction);
	CActionNode* WanderActionNode = new CActionNode(new CWanderAction(CharacterBehaviors, Obstacles));

	CFollowWanderDecisionNode* DecisionTreeRoot = new CFollowWanderDecisionNode(FollowActionNode, WanderActionNode);
	CDecisionMakingBehavior* DecisionTree = new CDecisionMakingBehavior(DecisionTreeRoot);

	Character = new CFlock(1, CharacterBehaviors, ofColor::black, DecisionTree, ofVec2f(50.0f, ofGetWindowHeight() - 50.0f));
	DecisionTreeRoot->SetFlock(Character);
	CharacterFollowAction->SetCharacter(Character);

	CBlackBoard* BlackBoard = new CBlackBoard();

	CSelector* BehaviorTreeRoot = new CSelector(0);

	CSequencer* SmellSequence = new CSequencer(1);
	BehaviorTreeRoot->AddChild(SmellSequence);

	CRandomizer* Randomizer = new CRandomizer(9);
	BehaviorTreeRoot->AddChild(Randomizer);
	Randomizer->AddChild(new CActionTask(2, new CWanderAction(MonsterBehaviors, Obstacles)));
	Randomizer->AddChild(new CActionTask(10, new CPatrolAction(MonsterBehaviors)));

	CCanSmellCharacterTask* CanSmellTask = new CCanSmellCharacterTask(3, Character);
	SmellSequence->AddChild(CanSmellTask);

	CSelector* SmellSelector = new CSelector(4);
	SmellSequence->AddChild(SmellSelector);

	CSequencer* EatSequence = new CSequencer(5);
	SmellSelector->AddChild(EatSequence);
	CCanEatCharacerTask* CanEatTask = new CCanEatCharacerTask(6, Character);
	EatSequence->AddChild(CanEatTask);
	CResetAction* ResetAction = new CResetAction(MonsterBehaviors, Obstacles, Character);
	EatSequence->AddChild(new CActionTask(7, ResetAction));

	CFollowAction* MonsterFollowAction = new CFollowAction(MonsterBehaviors, MonsterPath, DivisionScheme, Target, Graph, Heuristic);
	SmellSelector->AddChild(new CActionTask(8, MonsterFollowAction));

	CDecisionMakingBehavior* BehaviorTree = new CBehaviorTree(0, BehaviorTreeRoot, BlackBoard);

	Monster = new CFlock(1, MonsterBehaviors, ofColor::green, BehaviorTree, ofVec2f(ofGetWindowWidth() - 50.0f, 50.0f));
	CanEatTask->SetMonster(Monster);
	CanSmellTask->SetMonster(Monster);
	MonsterFollowAction->SetCharacter(Character);
	MonsterFollowAction->SetMonster(Monster);
	ResetAction->SetMonster(Monster);
}

//=======================================================================================================================
void ofApp::update()
{
	if (Character)
	{
		Character->Update(ofGetLastFrameTime());
	}

	if (Monster)
	{
		Monster->Update(ofGetLastFrameTime());
	}
}

//=======================================================================================================================
void ofApp::draw()
{
	ofSetColor(ofColor::black);

	ofDrawBitmapString("Avoid the green monster by clicking a location to run to!", 50, 50);

	ofDrawRectangle(Target.x, Target.y, TargetSize, TargetSize);

	for (auto Obstacle : Obstacles)
	{
		if (Obstacle)
		{
			Obstacle->Draw();
		}
	}

	if (Character)
	{
		Character->Draw();
	}

	if (Monster)
	{
		Monster->Draw();
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

	if (Character)
	{
		Character->SetBehavior(EBehavior::FOLLOW);
	}
}

//=======================================================================================================================
void ofApp::CreateObstacles()
{
	Obstacles.push_back(new CObstacle(100.0f, 100.0f, 100.0f, 100.0f));
	Obstacles.push_back(new CObstacle(300.0f, 300.0f, 100.0f, 300.0f));
	Obstacles.push_back(new CObstacle(500.0f, 600.0f, 200.0f, 100.0f));
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
