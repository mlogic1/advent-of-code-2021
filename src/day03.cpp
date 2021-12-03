/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 03 - Binary Diagnostic                           *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <bitset>
#include <iostream>

static constexpr const char* INPUT_FILE = "day03a.txt";
static constexpr int BIT_COUNT = 12;


namespace Day03
{
	enum class SearchMode
	{
		OXYGEN,
		SCRUBBER
	};

	static int BitCount(const string& str, char bit)
	{
		return std::count_if(str.cbegin(), str.cend(), [bit](char value){ return value == bit; });
	}

	static void GetMostCommonBit(const string& str, char& mostCommonBit)  // mostCommonBit is set to -1 if there's an equal amount of 0s and 1s
	{
		const int zeroCount =  BitCount(str, '0');
		const int oneCount = str.length() - zeroCount;
		if (zeroCount == oneCount)
		{
			mostCommonBit = -1;
		}else if (zeroCount > oneCount)
		{
			mostCommonBit = '0';
		}else
		{
			mostCommonBit = '1';
		}
	}

	static int CalculateRating(StringVector data, SearchMode searchMode)
	{
		bool lastElement = false;
		for (int i = 0; i < BIT_COUNT; ++i)
		{
			if (lastElement == true)
				break;

			string str("");
			for (StringVector::const_iterator it = data.cbegin(); it != data.cend(); ++it)
				str += (*it).at(i);

			char targetBit;
			GetMostCommonBit(str, targetBit);
			if (searchMode == SearchMode::OXYGEN)
			{
				if (targetBit == -1)
					targetBit = '1';
			}
			else
			{
				if (targetBit == -1)
				{
					targetBit = '0';
				}
				else
				{
					targetBit = (targetBit == '0') ? '1' : '0';
				}
			}

			for (StringVector::iterator it = data.begin(); it != data.end();)
			{
				if ((*it).at(i) != targetBit)
				{
					it = data.erase(it);

					if (data.size() == 1)
					{
						lastElement = true;
						break;
					}
				}
				else
				{
					++it;
				}
			}
		}
		std::bitset<BIT_COUNT> binary(data[0]);
		return binary.to_ulong();
	}

	void PartA(StringVector& input)
	{
		constexpr int BIT_COUNT = 12;
		const int INPUT_SIZE_HALF = input.size() / 2;

		int zeroCount[BIT_COUNT] = {};
		for (int i = 0; i < BIT_COUNT; ++i)
		{
			for (const string& number : input)
			{
				if (number.at(i) == '0')
					++zeroCount[i];
			}
		}

		std::string gammaStr("");
		for (int i = 0; i < BIT_COUNT; ++i)
		{
			gammaStr += (zeroCount[i] > INPUT_SIZE_HALF) ? "0" : "1";
		}
		std::bitset<BIT_COUNT> gamma(gammaStr);
		std::bitset<BIT_COUNT> epsilon(gamma);
		epsilon.flip();

		std::cout << "Day 3 Part 1: Power consumption of the submarine is: " << gamma.to_ulong() * epsilon.to_ulong() << std::endl;
	}

	void PartB(StringVector& data)
	{
		int oxygenRating = CalculateRating(data, SearchMode::OXYGEN);
		int co2Rating = CalculateRating(data, SearchMode::SCRUBBER);

		std::cout << "Day 3 Part 2: Life support rating " << oxygenRating * co2Rating << std::endl;
	}

	void RunDay()
	{
		StringVector input;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 03 input file fail" << std::endl;
			return;
		}

		PartA(input);
		PartB(input);
	}
}

