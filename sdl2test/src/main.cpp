#define SDL_MAIN_HANDLED

#include "SDL.h"

#include <iostream>
#include <array>
#include <random>

#include "cell.h"
#include "grid.h"

#include "global.h"

int main()
{
    srand(time(NULL));

    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize the SDL2 library\n";
        return -1;
    }

    SDL_Window *window = SDL_CreateWindow("MazeGenerator",
                                          SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED,
                                          WINDOW_WIDTH, WINDOW_HEIGHT,
                                          0);
    //change 1
       
    if(!window)
    {
        std::cout << "Failed to create window\n";
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
   
    SDL_Event eventType;
    bool gameRunning = true;
    
    Grid grid;
    grid.SetCurrent(grid[grid.index(0, 0)]);

    std::vector<std::shared_ptr<Cell>> stack;

    while (gameRunning)
    {

        //updating
        while (SDL_PollEvent(&eventType))
        {
            if (eventType.type == SDL_QUIT)
                gameRunning = false;
        }

        //rendering
        SDL_RenderClear(renderer);


        grid.current->visited = true;

        std::shared_ptr<Cell> next = grid.checkNeighbors(grid.current);
        if (next)
        {
            next->visited = true;

            stack.push_back(next);

            grid.removeWalls(*grid.current, *next);
            
            grid.SetCurrent(next);
        }
        else if (!stack.empty())
        {
            grid.SetCurrent(stack.back());
            stack.pop_back();
        }
        
       

        for (int i = 0; i < GRID_SIZE; i++)
        {
            grid[i]->Draw(renderer);

        }
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}