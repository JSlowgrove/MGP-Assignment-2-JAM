#pragma once

#include <vector>
#include <SDL.h>
#include "State.h"

/**
@brief Creates a StateManager object.
Creates a StateManager object to be inherited.
DISCLAMER ~ This is a modified version of my PGG Assignment 1 State Manager class.
*/
class JAM_StateManager
{
private:
	/**The current states that are in use*/
	std::vector<JAM_State*> currentStates;

public:
	/**
	Constructs a StateManager object.
	*/
	JAM_StateManager();

	/**
	Destructs a StateManager object.
	*/
	~JAM_StateManager();

	/**
	Adds a new state to the current stack of states.
	@param State * A pointer to the State in use.
	*/
	void addState(JAM_State* state);

	/**
	Changes the current State to a new State.
	@param State * A pointer to the State in use.
	*/
	void changeState(JAM_State* state);

	/**
	Removes the last State from the vector.
	*/
	void removeLastState();

	/**
	Handles the user input.
	The input function that will allow the equivalent input function to run in the current State.
	@returns bool If false then quit the application.
	*/
	bool input();

	/**
	Updates the current State.
	The update function that will allow the equivalent update function to run in the current State.
	@param float The delta time for use within the update function.
	*/
	void update(float dt);

	/**
	Draws the current State.
	The draw function that will allow the equivalent draw function to run in the current State.
	*/
	void draw();
};