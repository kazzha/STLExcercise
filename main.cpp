#include <iostream>
#include <string>
#include <sstream> // string stream
#include <vector>
#include "Ex3.h"
#include "map.h"
#include "Ex5.h"

/*
int main()
{
	std::string nick{ "Doggy" };
	int rarity{ 5 };
	std::string itemName{ "서리한" };

	std::ostringstream oss;

	oss << nick << "님이 " << rarity << "성" << itemName << "을/를 강화 성공!" << std::endl;

	std::cout << oss.str() << std::endl;

	//////////////////////////////////////////

	char output[512];
	snprintf(output, sizeof(output),
		"%s님이 %d성 %s을/를 강화 성공!", nick.c_str(), rarity, itemName.c_str());

	std::cout << output << std::endl;

	return 0;
}
*/

/*
int main()
{
	std::vector<int> v1{ 1,2,3,4,5,6 };

	std::vector<int> v5; // 원소가 0개인 벡터
	v5.push_back(2); // back에 붙인다는 뜻
	v5.push_back(3);

	return 0;
}

*/

int main()
{
	/*
	PrintVector2D();
	std::string s = "acdfc1";
	std::string t = "dca1cf";
	
	std::cout << std::boolalpha << IsSameImage(s, t) << std::endl; // boolalpah = 참거짓을 알파벳으로 쓴다
	*/

	std::cout << MaxLetter("hhhe");
	return 0;
}