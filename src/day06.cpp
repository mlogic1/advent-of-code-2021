/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 06 - Lanternfish                                 *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day06a.txt";
static constexpr int DAYS_A = 80;
static constexpr int DAYS_B = 256;

namespace Day06
{
	unsigned long long CalculateFish(const IntVector& fish, const int days)
	{
		long long fishTimes[9] = { 0 };
		std::for_each(fish.cbegin(), fish.cend(), [&fishTimes](int time)
		{
				++fishTimes[time];
		});

		for (int i = 0; i < days; ++i)
		{
			long long newFish = fishTimes[0];
			for (int j = 0; j < 8; j++)
			{
				fishTimes[j] = fishTimes[j + 1];
			}
			
			fishTimes[8] = newFish;
			fishTimes[6] += newFish;
		}

		unsigned long long totalFish = 0;
		for (int i = 0; i < 9; ++i)
		{
			totalFish += fishTimes[i];
		}

		return totalFish;
	}

	void PartA(const IntVector& input)
	{
		std::cout << "Day 6 Part 1: " << CalculateFish(input, DAYS_A) << std::endl;
	}

	void PartB(const IntVector& input)
	{
		std::cout << "Day 6 Part 2: " << CalculateFish(input, 256) << std::endl;
	}

	void RunDay()
	{
		IntVector fish;

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
		}
		
		PartA(fish);
		PartB(fish);
	}
}