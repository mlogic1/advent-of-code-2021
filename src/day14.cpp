/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 12 - Extended Polymerization                     *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

using CharPair = std::pair<char, char>;

// static constexpr const char* INPUT_FILE = "day14.txt";
static constexpr const char* INPUT_FILE = "day14test.txt";

namespace Day14
{
	void PartA(const string& polyTemplate, const std::map<CharPair, char>& pairs)
	{
		string result = polyTemplate;
		std::map<char, int> elementCounts;
	
		for (char c : polyTemplate)
			elementCounts.emplace(c, 0);

		for (auto pair : pairs)
			elementCounts.emplace(pair.second, 0);

		std::map<CharPair, char>::const_iterator pEnd = pairs.cend();
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < result.size();)
			{
				auto lookup = pairs.find({ result[j], result[j + 1] });
				if (lookup != pEnd)
				{
					result.insert(j + 1, 1, lookup->second);
					j += 2;
				}
				else
				{
					++j;
				}
			}
		}

		int mostCommonCharCount = 0, leastCommonCharCount = INT_MAX;
		for (auto elemCount : elementCounts)
		{
			const int count = std::count(result.cbegin(), result.cend(), elemCount.first);
			if (count < leastCommonCharCount)
			{
				leastCommonCharCount = count;
			}

			if (count > mostCommonCharCount)
			{
				mostCommonCharCount = count;
			}
		}

		std::cout<<"Day 14 part 1: " << mostCommonCharCount - leastCommonCharCount << std::endl;
	}

	void PartB(const string& polyTemplate, const std::map<CharPair, char>& pairs)
	{
		std::cout<<"Day 14 part 2 not solved." << std::endl;
	}

	void RunDay()
	{
		string polyTemplate;
		std::map<CharPair, char> pairs;
		{
			StringVector input;
			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 11 input file fail" << std::endl;
				return;
			}

			polyTemplate = input[0];

			for (int i = 2, len = input.size(); i < len; ++i)
			{
				const string line = input[i];
				CharPair pair{ line.at(0) , line.at(1) };
				char result = line.back();
				pairs.emplace(pair, result);
			}
		}
		
		PartA(polyTemplate, pairs);
		PartB(polyTemplate, pairs);
	}
}