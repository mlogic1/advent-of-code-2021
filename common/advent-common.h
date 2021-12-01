#include <fstream>
#include <string>
#include <vector>

using std::string;
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
}