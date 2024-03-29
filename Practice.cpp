#include <iostream>
#include <vector>
#include <algorithm>

/*
int main() {

	int value{}, num{};

	std::vector<int> v1;
	while (std::cin >> value)
	{
		v1.push_back(value);
	}

	for (int e : v1)
	{
		num += e;
	}

	std::cout << num;
	

}

*/

/*
int main()
{
	int input{}, min{}, minIndex{};

	std::vector<int> v2;

	while (std::cin >> input)
	{
		v2.push_back(input);
	}

	min = v2[0];

	for (int i=0; i < v2.size(); i++)
	{
		if(min > v2[i])
		{
			minIndex = i;
		}
	}

	std::cout << minIndex;

}

*/

/*
// {1, 2, 3, 4} print operator
std::ostream& operator << (std::ostream& os, std::vector<int> v)
	{
		std::cout << "{ ";
		for (std::vector<int>::iterator it=v.begin(); it != v.end(); it++)
		{
			std::cout << *it;

			if (it != v.end() - 1)
			{
				std::cout << ", ";
			}
		}

		std::cout << " }";
		return os;
	}

int main()
{
	std::vector<int> numbers{ 5,2,3,1,4 };

	std::vector<int>::iterator result = std::min_element(numbers.begin(), numbers.end());
	std::cout << (result - numbers.begin()) << std::endl;

	std::cout << numbers;
}

*/

/*
struct Student
{
	int Number;
	int Score;
	std::string Name;
};

std::ostream& operator << (std::ostream& os, const std::vector<Student>& students)
{
	for (const auto& e : students)
	{
		std::cout << e.Number << " : " << e.Name << ", " << e.Score << std::endl;
	}
	return os;
}

int main()
{
	std::vector<Student> student{ {1, 100, "Doggy"}, {2, 50, "Kitty"},
		{3, 90, "Piggy"}, {4, 20, "Bunny"} };

	std::cout << "-----------오름차순 정렬------------" << std::endl;
	std::sort(student.begin(), student.end(), [](Student& x, Student& y)->bool
		{ return x.Score > y.Score; });
	std::cout << student;

	std::cout << "-----------내림차순 정렬------------" << std::endl;

	std::sort(student.begin(), student.end(), [](Student& x, Student& y)->bool
		{ return x.Score < y.Score; });
	std::cout << student;
}
*/

int main()
{
	std::vector<int> numbers{ 5,2,3,1,4 };

	// 이터레이터
	for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	//for_each
	std::for_each(numbers.begin(), numbers.end(), [](const int& val) {std::cout << val << std::endl;});

	// range-base
	for (const auto& e : numbers) { std::cout << e << std::endl; }
}