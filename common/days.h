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

#endif
