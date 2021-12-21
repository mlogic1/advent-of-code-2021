/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 09 - Smoke Basin                                 *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day09a.txt";
static constexpr int GRID_ROWS = 100;
static constexpr int GRID_COLS = 100;

// static constexpr const char* INPUT_FILE = "day09test.txt";
// static constexpr int GRID_ROWS = 5;
// static constexpr int GRID_COLS = 10;

namespace Day09
{
	int** CreateGrid()
	{
		int** grid = new int* [GRID_ROWS];
		
		for (int j = 0; j < GRID_ROWS; ++j)
		{
			grid[j] = new int[GRID_COLS];
		}

		return grid;
	}

	void DeleteGrid(int** grid)
	{
		for (int i = 0; i < GRID_ROWS; ++i)
		{
			delete[] grid[i];
		}
		delete[] grid;
	}

	IntVector GetNodeNeighbours(const int* const * grid, const int row, const int col)
	{
		IntVector neighbours;

		bool isCorner = true, isWall = true;
		
		// corners have 2 neighbours
		if (row == 0 && col == 0) {
			neighbours.emplace_back(grid[0][1]);
			neighbours.emplace_back(grid[1][0]);
		}
		else if (row == 0 && col == GRID_COLS - 1) {
			neighbours.emplace_back(grid[0][GRID_COLS - 2]);
			neighbours.emplace_back(grid[1][GRID_COLS - 1]);
		}
		else if (row == GRID_ROWS - 1 && col == 0) {
			neighbours.emplace_back(grid[GRID_ROWS - 2][0]);
			neighbours.emplace_back(grid[GRID_ROWS - 1][1]);
		}
		else if (row == GRID_ROWS - 1 && col == GRID_COLS - 1) {
			neighbours.emplace_back(grid[GRID_ROWS - 1][GRID_COLS - 2]);
			neighbours.emplace_back(grid[GRID_ROWS - 2][GRID_COLS - 1]);
		}else { isCorner = false; }

		if (isCorner)
			return neighbours;

		// walls have 3 neighbors
		if (row == 0) {
			neighbours.emplace_back(grid[row][col - 1]);
			neighbours.emplace_back(grid[row][col + 1]);
			neighbours.emplace_back(grid[row + 1][col]);
		}else if (row == GRID_ROWS - 1) {
			neighbours.emplace_back(grid[row][col - 1]);
			neighbours.emplace_back(grid[row][col + 1]);
			neighbours.emplace_back(grid[row - 1][col]);
		}else if (col == 0) {
			neighbours.emplace_back(grid[row][col - 1]);
			neighbours.emplace_back(grid[row][col + 1]);
			neighbours.emplace_back(grid[row + 1][col]);
		}
		else if (col == GRID_COLS - 1){
			neighbours.emplace_back(grid[row][col - 1]);
			neighbours.emplace_back(grid[row][col + 1]);
			neighbours.emplace_back(grid[row - 1][col]);
		}else { isWall = false; }
		
		if (isWall)
			return neighbours;
		
		// others have 4 neighbours
		neighbours.emplace_back(grid[row - 1][col]);
		neighbours.emplace_back(grid[row + 1][col]);
		neighbours.emplace_back(grid[row][col - 1]);
		neighbours.emplace_back(grid[row][col + 1]);

		return neighbours;
	}

	void PartA(const int* const* heightMap)
	{
		IntVector lowPoints;

		for (int i = 0; i < GRID_ROWS; ++i)
		{
			for (int j = 0; j < GRID_COLS; ++j)
			{
				int current = heightMap[i][j];
				IntVector neighbours = GetNodeNeighbours(heightMap, i, j);
				
				int smallestNeighbour = *std::min_element(neighbours.cbegin(), neighbours.cend());
				if (current < smallestNeighbour)
				{
					lowPoints.emplace_back(current);
				}
			}
		}

		uint32_t riskSum = 0;
		std::for_each(lowPoints.cbegin(), lowPoints.cend(), [&riskSum](int element) { riskSum += (element + 1); });
		
		std::cout << "Day 9 Part 1: " << riskSum << std::endl;
	}

	void PartB(const int* const* heightMap)
	{


		std::cout << "Day 9 Part 2: " << 1337 << std::endl;
	}

	void RunDay()
	{
		int** heightMap = nullptr;
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 09 input file fail" << std::endl;
			return;
		}

		heightMap = CreateGrid();

		for (int i = 0; i < GRID_ROWS; ++i)
		{
			for (int j = 0; j < GRID_COLS; ++j)
			{
				char c = input[i][j];
				heightMap[i][j] = c - '0';
			}
		}

		PartA(heightMap);
		PartB(heightMap);
		DeleteGrid(heightMap);
	}
}