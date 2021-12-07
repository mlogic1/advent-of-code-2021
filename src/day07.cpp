/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 07 - The Treachery of Whales                     *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day07a.txt";

namespace Day07
{
	void PartA(const IntVector& distances)
	{
		const int maxDistance = *std::max_element(distances.cbegin(), distances.cend());
		int minimalFuel = INT_MAX;
		for (int i = 0; i < maxDistance; ++i)
		{
			int consumedFuel = 0;
			for (int j = 0, len = distances.size(); j < len; ++j)
				consumedFuel += std::abs(distances[j] - i);

			if (consumedFuel < minimalFuel)
				minimalFuel = consumedFuel;
		}
		
		std::cout << "Day 7 Part 1: " << minimalFuel << std::endl;
	}

	void PartB(const IntVector& distances)
	{
		const int maxDistance = *std::max_element(distances.cbegin(), distances.cend());
		int minimalFuel = INT_MAX;
		for (int i = 0; i < maxDistance; ++i)
		{
			unsigned int consumedFuel = 0;
			for (int j = 0, len = distances.size(); j < len; ++j)
			{
				const int distance = std::abs(distances[j] - i);
				consumedFuel += ((distance * distance) + distance) / 2;
			}

			if (consumedFuel < minimalFuel)
				minimalFuel = consumedFuel;
		}

		std::cout << "Day 7 Part 2: " << minimalFuel << std::endl;
	}

	void RunDay()
	{
		IntVector distances;

		{
			StringVector input;

			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 07 input file fail" << std::endl;
				return;
			}

			StringVector strNumbers = common::SplitStringWithDelimiter(input[0], ',');
			for (const string& strNumber : strNumbers)
			{
				distances.emplace_back(std::stoi(strNumber));
			}
		}
		
		PartA(distances);
		PartB(distances);
	}
}