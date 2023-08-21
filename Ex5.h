#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


void PrintVector2D()
{
	int x{}, y{};
	std::cout << "세로 가로 : ";
	std::cin >> y >> x;

	std::vector<std::vector<int>> vec(y, std::vector<int>(x,-1));
	
	std::cout << "{" << std::endl;

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << "{";

		for (int j = 0; j < vec[i].size(); j++)
		{
			std::cout << vec[i][j];

			if (j < vec[i].size()-1)
			{
				std::cout << ",";
			}
		}
		std::cout << "}" ;

		if (i < vec.size() - 1)
		{
			std::cout << "," << std::endl;
		}
	}
	std::cout << std::endl << "}" << std::endl;
}

bool IsSameImage(std::string s, std::string t)
{
	std::sort(s.begin(), s.end());
	std::sort(t.begin(), t.end());

	return s == t;
}

char MaxLetter(const std::string& s)
{
	std::map<char, int> table;
	char maxChar{};
	int max{ -1 };

	for (const auto& e : s)
	{
		table[e]++;

		if (table[e] > max)
		{
			maxChar = e;
			max = table[e];
		}
	}

	return maxChar;
}