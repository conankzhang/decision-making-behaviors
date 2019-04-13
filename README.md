# Decision Making Algorithms

This project was built with openFrameworks v0.10.1 and Visual Studio 2017.
To give it a try, place the contents of this repository under your myApps directory!

## Directory Outline

1. src/Actions
   * Action.h/.cpp
     * A class that encapsulates actionable AIl logic
   * ActionManager.h/.cpp
     * A class that handles scheduling and updating Actions
   * FollowAction.h/.cpp
     * A game specific action that handles pathfinding
   * PatrolAction.h/.cpp
     * A game specific action that handles patrolling the edges of the screen
   * PriorityQueue.h
     * A priority queue data structure that implements removal
   * ResetAction.h
     * A game specific action that resets the game
   * WanderAction.h/.cpp
     * A game specific action that handles wandering around the environment

2. src/BehaviorTree
   * BehaviorTree.h/.cpp
     * A class that acts as an interface to the a behavior
   * BlackBoard.h/.cpp
     * A class that stores data for the tasks in a behavior tree
   * BlackBoardValue.h
     * A template class that enables a Blackboard to store generic values
   * Tick.h/.cpp
     * A class that helps with Re-entrant behavior in the Behavior Tree

   a. BehaviorTree/Tasks
   * ActionTask.h/.cpp
     * A task to encapsulate actions in a Behavior Tree
   * CanEatCharacterTask.h/.cpp
     * A game specific task to check if the monster can eat the player
   * CanEatCharacterTask.h/.cpp
     * A game specific task to check if the monster can sense the player
   * Inverter.h/.cpp
     * A task to invert the status code of a child task
   * Randomizer.h/.cpp
     * A task to execute a random child task
   * Selector.h/.cpp
     * A task to execute all child tasks until one return SUCCESS
   * Sequencer.h/.cpp
     * A task to execute all child tasks until one returns FAILURE
   * Task.h/.cpp
     * An class to act as the basis for all other tasks

3. src/DecisionMaking
  * ActionNode.h/.cpp
     * A class that encapsulates actions in a Decision Tree
  * DecisionMakingBehavior.h/.cpp
     * A class that represent a Decision Tree
  * DecisionNode.h/.cpp
     * A class that makes a choice on two branches
  * DecisionTreeNode.h/.cpp
     * An interface for all nodes in a Decision Tree

   a. DecisionMaking/Nodes
   * FollowWanderDecisionNode.h/.cpp
     * A game specific Decision Node to decide between Follow and Wander Actions

4. main.cpp
   * A file for the entry point into the program
5. ofApp.h/.cpp
   * A class that handles updating, drawing, and handling user input

## Running the Simulation

1. Open the decisionMakingBehaviors.sln
2. Build the project with Visual Studio with these settings:
   * Debug
   * Win32
3. Run the Local Windows Debugger

## Help the Black Agent!

* After the application loads you can click on white areas of the screens to get the black agent to navigate to that location.
  * Otherwise, the black agent will wander around.
* Black areas represent obstacles an agent will navigate around.
* The green agent is a monster looking to eat the black agent!
  * The green radius is its sense of smell.
    * If the black agent enters this radius, the green agent will start the chase!
  * The red radius is its bite range.
    * If the black agent enters this radius, its game over! The green and black agent will return to their original locations.
