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

#ifndef ADVENT_COMMON
#define ADVENT_COMMON

#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <type_traits>

using std::string;
using std::stringstream;
using std::vector;

using StringVector = vector<string>;
using IntVector = vector<int>;

namespace common
{
	static bool ReadEntireFileStrings(const std::string& fileName, StringVector& vec)
	{
		std::ifstream file(fileName);
		if (file.good())
		{
			std::string line;
			while (std::getline(file, line))
			{
				vec.emplace_back(line);
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	static bool ReadEntireFileInts(const std::string& fileName, IntVector& vec)
	{
		std::ifstream file(fileName);
		if (file.good())
		{
			std::string line;
			while (std::getline(file, line))
			{
				vec.emplace_back(std::stoi(line));
			}
		}
		else
		{
			return false;
		}

		return true;
	}

	static StringVector SplitStringWithDelimiter(const string& data, const char delimiter)
	{
		StringVector result;
		stringstream sstream(data);

		string temp;
		while (getline(sstream, temp, delimiter))
				result.push_back(temp);

		return result;
	}

	template<typename T>
	static T** CreateGrid(const int rows, const int columns)
	{
		T** result = new T* [rows];

		for (int i = 0; i < rows; ++i)
		{
			result[i] = new T[columns];
		}

		return result;
	}

	template<typename T>
	static void DeleteGrid(T** grid, int rows, int columns)
	{
		for (int i = 0; i < columns; ++i)
		{
			delete[] grid[i];
		}

		delete[] grid;
	}
}

#endif
