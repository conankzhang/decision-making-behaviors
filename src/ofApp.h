#pragma once

#include "ofMain.h"

#include <vector>
#include <stack>
#include "Movement/Behavior.h"

class CObstacle;
class CFlock;
class CDirectedWeightedGraph;
class CDirectedWeightedEdge;
class CDivisionScheme;
class CHeuristic;

struct SWeightedBehavior;

//=======================================================================================================================
class ofApp : public ofBaseApp
{
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	void CreateObstacles();

private:
	float TargetSize;
	ofVec2f Target;

	CFlock* Character;
	std::vector<SWeightedBehavior*> CharacterBehaviors;
	std::stack<const CDirectedWeightedEdge*> CharacterPath;


	CFlock* Monster;
	std::vector<SWeightedBehavior*> MonsterBehaviors;
	std::stack<const CDirectedWeightedEdge*> MonsterPath;

	CDivisionScheme* DivisionScheme;
	CDirectedWeightedGraph* Graph;
	CHeuristic* Heuristic;

	std::vector<CObstacle*> Obstacles;
};
