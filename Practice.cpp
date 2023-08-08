#include <iostream>
#include <vector>

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