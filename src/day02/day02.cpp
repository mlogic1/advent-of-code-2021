/************************  ADVENT OF CODE 2021 **********************************       *
**                                                                              *      /.\
**                         adventofcode.com                                     *     /..'\
**                                                                              *     /'.'\
**                         mlogic1 (https://github.com/mlogic1)                 *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                         Day 2 - Dive!                                        *   ^^^[_]^^^
**                                                                              *
**                                                                              *
**                                                                              *
********************************************************************************/


#include <advent-common.h>
#include <iostream>
#include <array>

static constexpr const char* INPUT_FILE = "day02a.txt";

void PartA(StringVector& input)
{
	int verticalPos = 0, horizonalPos = 0;
	for (const string& line : input)
	{
		size_t pos = line.find(' ');
		string command = line.substr(0, pos);
		int commandValue = std::stoi(line.substr(pos, line.length() - pos));

		if (command == "forward"){
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

int main(int argc, char* argv[])
{
	StringVector input;

	if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		return -1;

	PartA(input);
	PartB(input);
	return 0;
}