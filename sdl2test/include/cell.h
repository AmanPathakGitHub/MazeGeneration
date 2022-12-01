#pragma once
#include <iostream>
#include "SDL.h"
struct Cell
{
	Cell() {};
	Cell(SDL_Rect cellData) : cellData(cellData) {}
	SDL_Rect cellData = {};
	// ORDER: top right bottom left
	bool isCurrent = false;
	bool walls[4] = { true, true, true, true };
	bool visited = false;
	
	void Draw(SDL_Renderer* renderer);
};