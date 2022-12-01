#include "grid.h"

#include "global.h"
#include <vector>


Grid::Grid()
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		cells.push_back(std::make_shared<Cell>());
	}

	for (int x = 0; x < COLS; x++)
	{
		for (int y = 0; y < ROWS; y++)
		{
			uint32_t xindex = x;
			uint32_t yindex = y;

					
			int index = xindex + yindex * COLS;

	
			cells[index]->cellData = SDL_Rect({ x * CELL_WIDTH, y * CELL_WIDTH, CELL_WIDTH, CELL_WIDTH });
		}
	}

	

	current = cells[0];
}

Grid::~Grid()
{
}

void Grid::SetCurrent(const std::shared_ptr<Cell> newCurrent)
{
	current->isCurrent = false;
	newCurrent->isCurrent = true;
	current = newCurrent;
}

int Grid::index(uint32_t x, uint32_t y)
{

	if (x < 0 || x > COLS - 1 || y < 0 || y > ROWS - 1)
		return -1;

	return x + y * COLS;
}
std::shared_ptr<Cell> Grid::checkNeighbors(const std::shared_ptr<Cell>& cell)
{
	std::vector<std::shared_ptr<Cell>> neighbours;

	std::shared_ptr<Cell>& top =   Get(this->index((cell->cellData.x / CELL_WIDTH), (cell->cellData.y / CELL_WIDTH) - 1));
	std::shared_ptr<Cell>& left =   Get(this->index((cell->cellData.x / CELL_WIDTH) - 1, (cell->cellData.y / CELL_WIDTH)));
	std::shared_ptr<Cell>& bottom = Get(this->index((cell->cellData.x / CELL_WIDTH), (cell->cellData.y / CELL_WIDTH) + 1));
	std::shared_ptr<Cell>& right =  Get(this->index((cell->cellData.x / CELL_WIDTH) + 1, (cell->cellData.y / CELL_WIDTH)));

	if (top.get() != nullptr && !top->visited) neighbours.push_back(top);
	if (left.get() != nullptr && !left->visited) neighbours.push_back(left);
	if (right.get() != nullptr && !right->visited) neighbours.push_back(right);
	if (bottom.get() != nullptr && !bottom->visited) neighbours.push_back(bottom);

	if (neighbours.size() != 0)
	{
		int randCellIndex = rand() % neighbours.size();
		return neighbours[randCellIndex];
		
	}
	return std::shared_ptr<Cell>(nullptr);

}

std::shared_ptr<Cell>& Grid::Get(int16_t index)
{

	if (index < 0)
		return std::shared_ptr<Cell>(nullptr);

	return cells[index];
}


std::shared_ptr<Cell>& Grid::operator[](uint16_t index)
{
	return Get(index);
}

void Grid::removeWalls(Cell& cell1, Cell& cell2)
{
	int16_t directionx = cell1.cellData.x / CELL_WIDTH - cell2.cellData.x / CELL_WIDTH;
	
	if (directionx == 1)
	{
		cell1.walls[3] = false;
		cell2.walls[1] = false;
	}
	else if (directionx == -1)
	{
		cell1.walls[1] = false;
		cell2.walls[3] = false;
	}

	int16_t directiony = cell1.cellData.y / CELL_WIDTH - cell2.cellData.y / CELL_WIDTH;

	if (directiony == 1)
	{
		cell1.walls[0] = false;
		cell2.walls[2] = false;
	}
	else if (directiony == -1)
	{
		cell1.walls[2] = false;
		cell2.walls[0] = false;
	}
}
