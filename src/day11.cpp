/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 11 - Dumbo Octopus                               *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day11a.txt";
static constexpr int GRID_SIZE = 10;
#define FOR_MATRIX(expr) for (int i = 0; i < GRID_SIZE; ++i) { for (int j = 0; j < GRID_SIZE; ++j) { expr } }

namespace Day11
{
	class Octopus
	{
	public:
		Octopus(){}

		Octopus(int x, int y, int energy)
		{
			_x = x;
			_y = y;
			_energy = energy;
		}

		void AddNeighbours(vector<Octopus*> neighbours)
		{
			for (Octopus* neighbour : neighbours)
			{
				_neighbours.emplace_back(neighbour);
			}
		}

		void IncreaseEnergy()
		{
			++_energy;
			if (_energy > 9 && !_isFlashing)
			{
				_isFlashing = true;
				for (Octopus* neighbour : _neighbours)
				{
					neighbour->IncreaseEnergy();
				}
			}
		}

		int GetEnergy()
		{
			return _energy;
		}

		bool IsFlashing()
		{
			return _isFlashing;
		}

		void ResetEnergy()
		{
			_energy = 0;
			_isFlashing = false;
		}

	private:
		bool _isFlashing = false;
		int _x = 0, _y = 0;
		int _energy = 0;
		
		vector<Octopus*> _neighbours;
	};

	vector<Octopus*> GetNodeNeighbours(Octopus** grid, const int row, const int col)
	{
		vector<Octopus*> neighbours;
		bool isCorner = true, isWall = true;
		
		// corners have 3 neighbours
		if (row == 0 && col == 0) {
			neighbours.emplace_back(&grid[0][1]);
			neighbours.emplace_back(&grid[1][0]);
			neighbours.emplace_back(&grid[1][1]);
		}
		else if (row == 0 && col == GRID_SIZE - 1) {
			neighbours.emplace_back(&grid[0][GRID_SIZE - 2]);
			neighbours.emplace_back(&grid[1][GRID_SIZE - 1]);
			neighbours.emplace_back(&grid[1][GRID_SIZE - 2]);
		}
		else if (row == GRID_SIZE - 1 && col == 0) {
			neighbours.emplace_back(&grid[GRID_SIZE - 2][0]);
			neighbours.emplace_back(&grid[GRID_SIZE - 1][1]);
			neighbours.emplace_back(&grid[GRID_SIZE - 2][1]);
		}
		else if (row == GRID_SIZE - 1 && col == GRID_SIZE - 1) {
			neighbours.emplace_back(&grid[GRID_SIZE - 1][GRID_SIZE - 2]);
			neighbours.emplace_back(&grid[GRID_SIZE - 2][GRID_SIZE - 1]);
			neighbours.emplace_back(&grid[GRID_SIZE - 2][GRID_SIZE - 2]);
		}else { isCorner = false; }

		if (isCorner)
			return neighbours;

		// walls have 5 neighbors
		if (row == 0) {
			neighbours.emplace_back(&grid[row][col - 1]);
			neighbours.emplace_back(&grid[row][col + 1]);
			neighbours.emplace_back(&grid[row + 1][col]);
			neighbours.emplace_back(&grid[row + 1][col - 1]);
			neighbours.emplace_back(&grid[row + 1][col + 1]);
		}else if (row == GRID_SIZE - 1) {
			neighbours.emplace_back(&grid[row][col - 1]);
			neighbours.emplace_back(&grid[row][col + 1]);
			neighbours.emplace_back(&grid[row - 1][col]);
			neighbours.emplace_back(&grid[row - 1][col - 1]);
			neighbours.emplace_back(&grid[row - 1][col + 1]);
		}else if (col == 0) {
			neighbours.emplace_back(&grid[row - 1][col]);
			neighbours.emplace_back(&grid[row - 1][col + 1]);
			neighbours.emplace_back(&grid[row][col + 1]);
			neighbours.emplace_back(&grid[row + 1][col]);
			neighbours.emplace_back(&grid[row + 1][col + 1]);
		}
		else if (col == GRID_SIZE - 1){
			neighbours.emplace_back(&grid[row][col - 1]);
			neighbours.emplace_back(&grid[row + 1][col - 1]);
			neighbours.emplace_back(&grid[row - 1][col]);
			neighbours.emplace_back(&grid[row - 1][col - 1]);
			neighbours.emplace_back(&grid[row + 1][col]);
		}else { isWall = false; }
		
		if (isWall)
			return neighbours;
		
		// others have 8 neighbours
		neighbours.emplace_back(&grid[row - 1][col]);
		neighbours.emplace_back(&grid[row + 1][col]);
		neighbours.emplace_back(&grid[row][col - 1]);
		neighbours.emplace_back(&grid[row][col + 1]);
		neighbours.emplace_back(&grid[row - 1][col - 1]);
		neighbours.emplace_back(&grid[row - 1][col + 1]);
		neighbours.emplace_back(&grid[row + 1][col - 1]);
		neighbours.emplace_back(&grid[row + 1][col + 1]);

		return neighbours;
	}

	void PartA(Octopus** grid)
	{
		int flashCount = 0;
		for (int k = 0; k < 100; ++k)
		{
			// step
			for (int i = 0; i < GRID_SIZE; ++i)
			{
				for (int j = 0; j < GRID_SIZE; ++j)
				{
					Octopus* octo = &grid[i][j];
					octo->IncreaseEnergy();
				}
			}

			for (int i = 0; i < GRID_SIZE; ++i)
			{
				for (int j = 0; j < GRID_SIZE; ++j)
				{
					Octopus* octo = &grid[i][j];
					if (octo->IsFlashing())
					{
						++flashCount;
						octo->ResetEnergy();
					}
				}
			}
		}

		std::cout<<"Day 11 part 1: " << flashCount << std::endl;
	}

	void PartB(Octopus** grid)
	{
		unsigned int stepCount = 100;	// part A already ran first 100 steps
		while(true)
		{
			// step
			for (int i = 0; i < GRID_SIZE; ++i)
			{
				for (int j = 0; j < GRID_SIZE; ++j)
				{
					Octopus* octo = &grid[i][j];
					octo->IncreaseEnergy();
				}
			}
			++stepCount;

			bool allFlashing = true;
			for (int i = 0; i < GRID_SIZE; ++i)
			{
				for (int j = 0; j < GRID_SIZE; ++j)
				{
					Octopus* octo = &grid[i][j];
					if (octo->IsFlashing())
					{
						octo->ResetEnergy();
					}
					else
					{
						allFlashing = false;
					}
				}
			}

			if (allFlashing)
			{
				break;
			}
		}

		std::cout << "Day 11 Part 2: " << stepCount << std::endl;
	}

	void RunDay()
	{
		Octopus** grid = new Octopus*[GRID_SIZE];
		for (int i = 0; i < GRID_SIZE; ++i)
			grid[i] = new Octopus[GRID_SIZE];

		{
			StringVector input;
		
			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 11 input file fail" << std::endl;
				return;
			}

			FOR_MATRIX(
				grid[i][j] = Octopus(i, j, input[i].at(j) - '0');
			);

			FOR_MATRIX(
				vector<Octopus*> neighbours = GetNodeNeighbours(grid, i, j);
				grid[i][j].AddNeighbours(neighbours);
			);
		}
		
		PartA(grid);
		PartB(grid);

		for (int i = 0; i < GRID_SIZE; ++i)
		{
			delete[] grid[i];
		}
		delete[] grid;
	}
}