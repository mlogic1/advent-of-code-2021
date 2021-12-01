/************************  ADVENT OF CODE 2021 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 1 - Sonar Sweep                                  *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/


#include <advent-common.h>
#include <iostream>
#include <array>

static constexpr const char* INPUT_FILE = "day01a.txt";

void PartA(IntVector& input)
{
	int biggerMeassurements = 0;
	int prevMeassurement = input.at(0);
	for (int i = 1, len = input.size(); i < len; ++i)
	{
		if (input[i] > prevMeassurement)
			++biggerMeassurements;
		prevMeassurement = input[i];
	}

	std::cout << "Day 1 Part 1: Number of times depth increased: " << biggerMeassurements << std::endl;
}

void PartB(IntVector& input)
{
	IntVector measurements;

	for (int i = 0, len = input.size() - 2; i < len; ++i)
		measurements.emplace_back(input[i] + input[i + 1] + input[i + 2]);
		
	int biggerMeassurements = 0;
	int prevMeassurement = measurements.at(0);
	for (int i = 1, len = measurements.size(); i < len; ++i)
	{
		if (measurements[i] > prevMeassurement)
			++biggerMeassurements;
		prevMeassurement = measurements[i];
	}

	std::cout << "Day 1 Part 2: Number of sum of measurements increased: " << biggerMeassurements << std::endl;
}

int main(int argc, char* argv[])
{
	IntVector input;

	if (!common::ReadEntireFileInts(INPUT_FILE, input))
		return -1;

	PartA(input);
	PartB(input);
	return 0;
}