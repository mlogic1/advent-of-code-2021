/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 05 - Hydrothermal Venture                        *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day05.txt";

namespace Day05
{
	void PartA()
	{
		std::cout << "Day 5 Part 1: " << 1337 << std::endl;
	}

	void PartB()
	{
		std::cout << "Day 5 Part 2: " << 1338 << std::endl;
	}

	void RunDay()
	{
		/*IntVector fish;

		{
			StringVector input;

			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 06 input file fail" << std::endl;
				return;
			}

			StringVector strNumbers = common::SplitStringWithDelimiter(input[0], ',');
			for (const string& strNumber : strNumbers)
			{
				fish.emplace_back(std::stoi(strNumber));
			}
		}*/
		
		PartA();
		PartB();
	}
}