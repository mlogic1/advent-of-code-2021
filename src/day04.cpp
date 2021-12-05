/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 04 - Giant Squid                                 *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day04a.txt";
static constexpr int BOARD_SIZE = 5;

#define FOR_MATRIX(expr) for (int i = 0; i < BOARD_SIZE; ++i) { for (int j = 0; j < BOARD_SIZE; ++j) { expr } }

namespace Day04
{
	class Board
	{
		public:
			Board(const vector<string>& data)
			{
				for (int i = 0; i < BOARD_SIZE; ++i)
				{
					stringstream sstream(data[i]);
					sstream >> numbers[i][0] >> numbers[i][1] >> numbers[i][2] >> numbers[i][3] >> numbers[i][4];
				}
			}

			void OnNumberDrawn(int num)
			{
				FOR_MATRIX(
					if (numbers[i][j] == num)
						marked[i][j] = true;
				)
			}

			bool IsWon()
			{				
				// rows
				for (int i = 0; i < BOARD_SIZE; ++i)
				{
					bool rowWin = true;
					for (int j = 0; j < BOARD_SIZE; ++j)
					{
						if (!marked[i][j])
						{
							rowWin = false;
							break;
						}
					}

					if (rowWin)
						return true;
				}
				
				// columns
				for (int i = 0; i < BOARD_SIZE; ++i)
				{
					bool columnWin = true;
					for (int j = 0; j < BOARD_SIZE; ++j)
					{
						if (!marked[j][i])
						{
							columnWin = false;
							break;
						}
					}

					if (columnWin)
						return true;
				}

				return false;
			}

			int GetUnmarkedNumbersSum() const
			{
				int sum = 0;

				FOR_MATRIX(
					if (!marked[i][j])
						sum += numbers[i][j];
				)

				return sum;
			}

		private:
			int numbers[BOARD_SIZE][BOARD_SIZE];
			bool marked[BOARD_SIZE][BOARD_SIZE] = {false};
	};

	void PartA(const IntVector& numbers, const vector<Board>& boards)
	{
		vector<Board> _boards = boards;

		for (int number : numbers)
		{
			for (Board& board : _boards)
			{
				board.OnNumberDrawn(number);
				if (board.IsWon())
				{
					std::cout << "Day 4 Part 1: " << board.GetUnmarkedNumbersSum() * number << std::endl;
					return;
				}
			}
		}

		std::cout << "Day 4 Part 1 failed " << std::endl;
	}

	void PartB(const IntVector& numbers, const vector<Board>& boards)
	{
		vector<Board> _boards = boards;
		
		for (int number : numbers)
		{
			for (vector<Board>::iterator it = _boards.begin(); it != _boards.end();)
			{
				it->OnNumberDrawn(number);
				if (it->IsWon())
				{					
					if (_boards.size() == 1)
					{
						std::cout << "Day 4 Part 2: " << it->GetUnmarkedNumbersSum() * number << std::endl;
						return;
					}
					else
					{
						it = _boards.erase(it);
					}
				}
				else
				{
					++it;
				}
			}
		}

		std::cout << "Day 4 Part 2 failed" << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 04 input file fail" << std::endl;
			return;
		}

		IntVector numbers;
		vector<Board> boards;

		{
			StringVector strNumbers = common::SplitStringWithDelimiter(input[0], ',');
			std::for_each(strNumbers.cbegin(), strNumbers.cend(), [&numbers](const string& str) { numbers.emplace_back(std::stoi(str)); });

			for (StringVector::const_iterator it = input.begin() + 1; it != input.cend(); it += 6)
			{
				StringVector boardData;
				
				std::copy(it + 1, it + 6, std::back_inserter(boardData));
				boards.emplace_back(boardData);
			}
		}

		PartA(numbers, boards);
		PartB(numbers, boards);
	}
}

