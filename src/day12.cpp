/************************  ADVENT OF CODE 2021 **********************************
**                         adventofcode.com                                     *       *
**                                                                              *      /.\
**                         mlogic1 (https://github.com/mlogic1)                 *     /..'\
**                                                                              *     /'.'\
**                                                                              *    /.''.'\
**                         Day 12 - Passage Pathing                             *    /.'.'.\
**                                                                              *   /'.''.'.\
**                                                                              *   ^^^[_]^^^
********************************************************************************/

#include <advent-common.h>
#include <days.h>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>

//static constexpr const char* INPUT_FILE = "day12.txt";
static constexpr const char* INPUT_FILE = "day12test.txt";

namespace Day12
{
	struct PathNode
	{
		const std::string name;
		bool isSmall;
		vector<PathNode*> connectedNodes;
	};

	void Traverse(PathNode* nodeStart, PathNode* nodeDst, int& pathCount, vector<PathNode*>& visited)
	{
		visited.emplace_back(nodeStart);

		if (nodeStart == nodeDst)
		{
			++pathCount;
		}
		else
		{
			for (PathNode* neighbour : nodeStart->connectedNodes)
			{
				if (std::count(visited.begin(), visited.end(), neighbour) == 0)
				{
					Traverse(neighbour, nodeDst, pathCount, visited);	
				}
			}
		}

		visited.erase(std::remove(visited.begin(), visited.end(), nodeStart));
	}

	void PartA(vector<PathNode*> cave)
	{
		int pathCount = 0;
		vector<PathNode*> visited;

		PathNode* startNode = *std::find_if(cave.begin(), cave.end(), [](const PathNode* node) { return node->name == "start"; });
		PathNode* endNode = *std::find_if(cave.begin(), cave.end(), [](const PathNode* node) { return node->name == "end"; });

		Traverse(startNode, endNode, pathCount, visited);

		std::cout<<"Day 12 part 1: " << pathCount << std::endl;
	}

	void PartB()
	{
		std::cout << "Day 12 Part 2: " << 1337 << std::endl;
	}

	void RunDay()
	{
		vector<PathNode*> cave;
		{
			StringVector input;
		
			if (!common::ReadEntireFileStrings(INPUT_FILE, input))
			{
				std::cout << "Day 12 input file fail" << std::endl;
				return;
			}

			for (const string& line : input)
			{
				StringVector nodePair = common::SplitStringWithDelimiter(line, '-');
				auto findResult = std::find_if(cave.begin(), cave.end(), [&nodePair](const PathNode* node) { return node->name == nodePair[0]; });
				
				if (findResult == cave.end())
				{
					bool isSmall = std::islower(nodePair[0].at(0));
					cave.emplace_back(new PathNode{ nodePair[0], isSmall });
				}

				findResult = std::find_if(cave.begin(), cave.end(), [&nodePair](const PathNode* node) { return node->name == nodePair[1]; });

				if (findResult == cave.end())
				{
					bool isSmall = std::islower(nodePair[1].at(0));
					cave.emplace_back(new PathNode{ nodePair[1], isSmall });
				}
			}

			for (const string& line : input)
			{
				StringVector nodePair = common::SplitStringWithDelimiter(line, '-');
				auto findResultLeft = std::find_if(cave.begin(), cave.end(), [&nodePair](const PathNode* node) { return node->name == nodePair[0]; });
				auto findResultRight = std::find_if(cave.begin(), cave.end(), [&nodePair](const PathNode* node) { return node->name == nodePair[1]; });

				if (findResultLeft == cave.end() || findResultRight == cave.end())
				{
					std::cout << "Error finding cave node, this shouldn't happen";
					return;
				}

				PathNode* left = *findResultLeft; 
				PathNode* right = *findResultRight;

				left->connectedNodes.emplace_back(right);
				right->connectedNodes.emplace_back(left);
			}
		}
		
		PartA(cave);
		PartB();
	}
}