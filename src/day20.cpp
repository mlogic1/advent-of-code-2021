/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 20 - Trench Map                                  *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

// static constexpr const char* INPUT_FILE = "day20.txt";
static constexpr const char* INPUT_FILE = "day20test.txt";

namespace Day20
{
	vector<char> GetNeighbours(char** grid, const int rows, const int columns, int x, int y)
	{
		vector<char> neighbours;

		bool isCorner = true, isWall = true;
		
		// corners have 3 neighbours
		if (x == 0 && y == 0) {
			neighbours.emplace_back(grid[0][1]);
			neighbours.emplace_back(grid[1][0]);
			neighbours.emplace_back(grid[1][1]);
		}
		else if (x == 0 && y == columns - 1) {
			neighbours.emplace_back(grid[0][columns - 2]);
			neighbours.emplace_back(grid[1][columns - 2]);
			neighbours.emplace_back(grid[1][columns - 1]);
		}
		else if (x == rows - 1 && y == 0) {
			neighbours.emplace_back(grid[columns - 2][0]);
			neighbours.emplace_back(grid[columns - 2][1]);
			neighbours.emplace_back(grid[columns - 1][1]);
		}
		else if (x == rows - 1 && y == columns - 1) {
			neighbours.emplace_back(grid[rows - 1][columns - 2]);
			neighbours.emplace_back(grid[rows - 2][columns - 1]);
			neighbours.emplace_back(grid[rows - 2][columns - 2]);
		}
		else { isCorner = false; }

		if (isCorner)
			return neighbours;

		// walls have 5 neighbors
		if (x == 0) {
			neighbours.emplace_back(grid[x][y - 1]);
			neighbours.emplace_back(grid[x][y + 1]);
			neighbours.emplace_back(grid[x + 1][y]);
			neighbours.emplace_back(grid[x + 1][y - 1]);
			neighbours.emplace_back(grid[x + 1][y + 1]);
		}
		else if (x == rows - 1) {
			neighbours.emplace_back(grid[x][y - 1]);
			neighbours.emplace_back(grid[x][y + 1]);
			neighbours.emplace_back(grid[x - 1][y]);
			neighbours.emplace_back(grid[x - 1][y - 1]);
			neighbours.emplace_back(grid[x - 1][y + 1]);
		}
		else if (y == 0) {
			neighbours.emplace_back(grid[x - 1][y]);
			neighbours.emplace_back(grid[x - 1][y + 1]);
			neighbours.emplace_back(grid[x][y + 1]);
			neighbours.emplace_back(grid[x + 1][y]);
			neighbours.emplace_back(grid[x + 1][y + 1]);
		}
		else if (y == columns - 1) {
			neighbours.emplace_back(grid[x][y - 1]);
			neighbours.emplace_back(grid[x + 1][y - 1]);
			neighbours.emplace_back(grid[x - 1][y]);
			neighbours.emplace_back(grid[x - 1][y - 1]);
			neighbours.emplace_back(grid[x + 1][y]);
		}
		else { isWall = false; }

		if (isWall)
			return neighbours;

		// others have 8 neighbours
		neighbours.emplace_back(grid[x - 1][y]);
		neighbours.emplace_back(grid[x + 1][y]);
		neighbours.emplace_back(grid[x][y - 1]);
		neighbours.emplace_back(grid[x][y + 1]);
		neighbours.emplace_back(grid[x - 1][y - 1]);
		neighbours.emplace_back(grid[x - 1][y + 1]);
		neighbours.emplace_back(grid[x + 1][y - 1]);
		neighbours.emplace_back(grid[x + 1][y + 1]);

		
		return neighbours;
	}

	void PartA(const string& algorithm, char** pixels, const int rows, const int columns)
	{
		vector<char> neighbours = GetNeighbours(pixels, rows, columns, 2, 2);




		std::cout<<"Day 20 part 1: " << 1337 << std::endl;
	}

	void PartB()
	{
		std::cout<<"Day 20 part 2 not solved." << std::endl;
	}

	void RunDay()
	{
		string algorithm;
		int rows, columns;
		char** pixels;
		{
			StringVector input;
			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 20 input file fail" << std::endl;
				return;
			}

			algorithm = input[0];
			StringVector pixelData;

			for (int i = 2, len = input.size(); i < len; ++i)
			{
				pixelData.emplace_back(input[i]);
			}

			rows = pixelData.size();
			columns = pixelData[0].length();
			pixels = common::CreateGrid<char>(pixelData[0].length(), columns);
			for (int i = 0; i < rows; ++i)
			{
				for (int j = 0; j < columns; ++j)
				{
					pixels[i][j] = pixelData[i].at(j);
				}
			}
		}
		
		PartA(algorithm, pixels,rows, columns);
		PartB();

		common::DeleteGrid<char>(pixels, rows, columns);
	}
}