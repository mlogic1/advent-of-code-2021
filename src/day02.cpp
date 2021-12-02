/************************  ADVENT OF CODE 2021 **********************************       
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 02 - Dive!                                       *    /.'.'.\
**                                                                              *	/'.''.'.\
**                                                                              *	^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <iostream>
#include <array>

static constexpr const char* INPUT_FILE = "day02a.txt";

namespace Day02
{
	void PartA(StringVector& input)
	{
		int verticalPos = 0, horizonalPos = 0;
		for (const string& line : input)
		{
			size_t pos = line.find(' ');
			string command = line.substr(0, pos);
			int commandValue = std::stoi(line.substr(pos, line.length() - pos));

			if (command == "forward") {
				horizonalPos += commandValue;
			}
			else if (command == "down") {
				verticalPos += commandValue;
			}
			else if (command == "up") {
				verticalPos -= commandValue;
			}
		}

		std::cout << "Day 2 Part 1: Depth and horizonal position product: " << verticalPos * horizonalPos << std::endl;
	}

	void PartB(StringVector& input)
	{
		int verticalPos = 0, horizonalPos = 0, aim = 0;
		for (const string& line : input)
		{
			size_t pos = line.find(' ');
			string command = line.substr(0, pos);
			int commandValue = std::stoi(line.substr(pos, line.length() - pos));

			if (command == "forward") {
				horizonalPos += commandValue;
				verticalPos += aim * commandValue;
			}
			else if (command == "down") {
				aim += commandValue;
			}
			else if (command == "up") {
				aim -= commandValue;
			}
		}

		std::cout << "Day 2 Part 2: Depth and horizonal position product: " << verticalPos * horizonalPos << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 02 input file fail" << std::endl;
			return;
		}
			

		PartA(input);
		PartB(input);
	}
}

