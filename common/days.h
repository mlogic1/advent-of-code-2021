/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                                                                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#ifndef ADVENT_DAYS
#define ADVENT_DAYS

#include <advent-common.h>

namespace Day01
{
	void RunDay();

	void PartA(IntVector& input);
	void PartB(IntVector& input);
}

namespace Day02
{
	void RunDay();

	void PartA(StringVector& input);
	void PartB(StringVector& input);
}

namespace Day03
{
	void RunDay();

	void PartA(StringVector& input);
	void PartB(StringVector& input);
}

namespace Day04
{
	void RunDay();
	class Board;
	void PartA(const IntVector& numbers, const vector<Board>& boards);
	void PartB(const IntVector& numbers, const vector<Board>& boards);
}

/*namespace Day05
{
	void RunDay();
	
	void PartA();
	void PartB();
}*/

namespace Day06
{
	void RunDay();
	
	void PartA(const IntVector& input);
	void PartB(const IntVector& input);
}

namespace Day07
{
	void RunDay();
	
	void PartA(const IntVector& distances);
	void PartB(const IntVector& distances);
}

namespace Day10
{
	void RunDay();
	
	void PartA(const StringVector& input, StringVector& incompleteLines);
	void PartB(const StringVector& incompleteLines);
}

namespace Day11
{
	void RunDay();
	
	class Octopus;
	void PartA(Octopus** grid);
	void PartB(Octopus** grid);
}


namespace Day14
{
	void RunDay();
	
	
	void PartA(const string& polyTemplate, const std::map<std::pair<char, char>, char>& pairs);
	void PartB(const string& polyTemplate, const std::map<std::pair<char, char>, char>& pairs);
}

#endif
