#include <iostream>
#include <string>
#include <sstream> // string stream
#include <vector>
#include "Ex3.h"
#include "map.h"

/*
int main()
{
	std::string nick{ "Doggy" };
	int rarity{ 5 };
	std::string itemName{ "������" };

	std::ostringstream oss;

	oss << nick << "���� " << rarity << "��" << itemName << "��/�� ��ȭ ����!" << std::endl;

	std::cout << oss.str() << std::endl;

	//////////////////////////////////////////

	char output[512];
	snprintf(output, sizeof(output),
		"%s���� %d�� %s��/�� ��ȭ ����!", nick.c_str(), rarity, itemName.c_str());

	std::cout << output << std::endl;

	return 0;
}
*/

/*
int main()
{
	std::vector<int> v1{ 1,2,3,4,5,6 };

	std::vector<int> v5; // ���Ұ� 0���� ����
	v5.push_back(2); // back�� ���δٴ� ��
	v5.push_back(3);

	return 0;
}

*/

int main()
{
	Ex4();
}