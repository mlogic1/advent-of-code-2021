/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 10 - Syntax Scoring                              *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

static constexpr const char* INPUT_FILE = "day10a.txt";

namespace Day10
{
	const vector<char> ClosedCharacters = { ')', ']', '}', '>' };

	const std::map<char, char> pairs =
	{
    	{')', '('},
		{']', '['},
		{'}', '{'},
		{'>', '<'}
	};

	const std::map<char, char> pairsClosed =
	{
		{'(', ')'},
		{'[', ']'},
		{'{', '}'},
		{'<', '>'}
	};

	const std::map<char, int> scoresA = 
	{
		{')', 3},
		{']', 57},
		{'}', 1197},
		{'>', 25137}
	};

	const std::map<char, int> scoresB =
	{
		{ ')', 1},
		{ ']', 2},
		{ '}', 3},
		{ '>', 4}
	};

	bool IsClosedCharacter(char c)
	{
		return std::count(ClosedCharacters.cbegin(), ClosedCharacters.cend(), c) > 0;
	}


	void PartA(const StringVector& input, StringVector& incompleteLines)
	{
		int score = 0;
		for (int i = 0, len = input.size(); i < len; ++i)
		{
			vector<char> openCharacters;
			bool lineValid = true;
			for (char c : input[i])
			{
				if (IsClosedCharacter(c))
				{
					if (pairs.at(c) != openCharacters.back())
					{
						score += scoresA.at(c);
						lineValid = false;
						break;
					}
					else
					{
						openCharacters.pop_back();
					}
				}
				else
				{
					openCharacters.emplace_back(c);
				}
			}
			if (lineValid)
				incompleteLines.emplace_back(input[i]);
		}

		std::cout<<"Day 10 part 1 score: " << score << std::endl;
	}

	void PartB(const StringVector& incompleteLines)
	{
		vector<uint64_t> scores;

		for (int i = 0, len = incompleteLines.size(); i < len; ++i)
		{
			vector<char> openCharacters;
			scores.emplace_back(0);
			for (char c : incompleteLines[i])
			{
				if (IsClosedCharacter(c))
				{
					openCharacters.pop_back();
				}
				else
				{
					openCharacters.emplace_back(c);
				}
			}

			vector<char> appendedCharacters;
			for (char c : openCharacters)
			{
				appendedCharacters.emplace_back(pairsClosed.at(c));
			}
			std::reverse(appendedCharacters.begin(), appendedCharacters.end());
			
			for (char c : appendedCharacters)
			{
				scores[i] = (scores[i] * 5) + scoresB.at(c);
			}
		}
		
		std::sort(scores.begin(), scores.end());

		std::cout << "Day 10 Part 2: " << scores.at(std::ceil(scores.size() / 2)) << std::endl;
	}

	void RunDay()
	{
		StringVector input;
		StringVector incompleteLines;

		if (!common::ReadEntireFileStrings(INPUT_FILE, input))
		{
			std::cout << "Day 10 input file fail" << std::endl;
			return;
		}

		PartA(input, incompleteLines);
		PartB(incompleteLines);
	}
}