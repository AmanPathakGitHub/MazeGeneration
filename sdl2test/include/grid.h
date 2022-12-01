#pragma once

#include <SDL.h>

#include <vector>
#include <array>
#include <memory>

#include "global.h"
#include "cell.h"

class Grid
{
public:
	std::shared_ptr<Cell> current;

	Grid();
	~Grid();
	
	void SetCurrent(const std::shared_ptr<Cell> newCurrent);

	std::shared_ptr<Cell>& Get(int16_t index);
	std::shared_ptr<Cell>& operator[](uint16_t index);
	
	int index(uint32_t x, uint32_t y);
	std::shared_ptr<Cell> checkNeighbors(const std::shared_ptr<Cell>& cell);

	void removeWalls(Cell& cell1, Cell& cell2);
private:
	std::vector<std::shared_ptr<Cell>> cells;
};