#include "cell.h"

void Cell::Draw(SDL_Renderer* renderer)
{

	if (visited)
	{

		if(isCurrent)
			SDL_SetRenderDrawColor(renderer, 3, 255, 95, 255);
		else
			SDL_SetRenderDrawColor(renderer, 0, 100, 0, 255);
		SDL_RenderFillRect(renderer, &cellData);

	}

	//walls[1] = false;
	//walls[3] = false;

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	//top
	if (walls[0]) SDL_RenderDrawLine(renderer, cellData.x, cellData.y, cellData.x + cellData.w, cellData.y);
	//right
	if (walls[1]) SDL_RenderDrawLine(renderer, cellData.x + cellData.w, cellData.y, cellData.x + cellData.w, cellData.y + cellData.h);
	//bottom
	if (walls[2]) SDL_RenderDrawLine(renderer, cellData.x + cellData.w, cellData.y + cellData.h, cellData.x, cellData.y + cellData.h);
	//left
	if (walls[3]) SDL_RenderDrawLine(renderer, cellData.x, cellData.y + cellData.h, cellData.x, cellData.y);
}
