#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

/*struct Student
{
	int mNumber;
	int mScore;
	std::string mName;
};

void Ex4()
{
	std::map<int, Student> students{
	{1,{1,100,"Doggy"}},
	{2,{2,50,"Kitty"}},
	{3,{3, 90,"Piggy"}},
	{4,{4,30,"Bunny"}}
	};
	students.insert(std::make_pair<int, Student>(5, { 5,80,"Mansu" }));

	for (auto student : students)
	{
		std::cout << student.second.mNumber << " : " <<
			student.second.mName << ", " <<
			student.second.mScore << std::endl;
	}
}
*/

class Student
{
public:
	int mNumber;
	std::string mName;
	int mScore;

public:
	void Print() const
	{
		std::cout << "[" << mNumber << "]" <<
			mName << " : " << mScore << std::endl;
	}
};

void AddStudent(std::vector<Student>& v)
{
	std::cout << "��ȣ �̸� ���� : ";
	Student newStudent{};
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		/*for (const auto& e : v) // find ����� ���� ����������
		{
			if (e.mNumber == newStudent.mNumber) 
			{
				std::cout << "�ߺ��� ��ȣ�Դϴ�" << std::endl;
				return;
			}
		}*/

		auto itr = std::find_if(v.begin(), v.end(), [&](const auto& e) 
			{return e.mNumber == newStudent.mNumber; });
		if (itr != v.end())
		{
			std::cout << "�ߺ��� ��ȣ�Դϴ�." << std::endl;
			return;
		}
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "�߸��� �Է��Դϴ�." << std::endl;
	}
}

void RemoveStudent(std::vector<Student>& v)
{
	std::cout << "������ ��ȣ�� �Է��ϼ��� : ";
	int number;
	if (std::cin >> number)
	{
		/*for (auto itr = v.begin(); itr != v.end(); itr++)
		{
			if (itr->mNumber == number)
			{
				v.erase(itr);
				break;
			}
		}*/

		// erase-remove idiom
		v.erase(std::remove_if(v.begin(), v.end(), [&](auto& e) {return e.mNumber == number; }));
	}
	else
	{
		std::cout << "��ȣ�� �Է��� �ּ���" << std::endl;
	}

}

void PrintStudents(const std::vector<Student>& v)
{
	for (const auto& e : v)
	{
		e.Print();
	}
}

void PrintAverage(const std::vector<Student>& v)
{
	int total{};

	for (const auto& e : v)
	{
		total += e.mScore;
	}

	std::cout << "���� : " << total << ", ��� : " << total / v.size() << std::endl;

}
void PrintOverAverage(const std::vector<Student>& v)
{
	int total{};

	for (const auto& e : v)
	{
		total += e.mScore;
	}
	int average = total / static_cast<int>(v.size());
	for (const auto& e : v)
	{
		if (e.mScore >= average)
		{
			e.Print();
		}
	}
}
void Ex4()
{
	/* {��ȣ, �̸�  ����} */
	std::vector<Student> stdents_v{
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 40},
		{4, "Choi", 30}
	};


	bool isQuit{ false };

	while (!isQuit)
	{
		std::cout << "1. �л� �߰�" << std::endl;
		std::cout << "2. �л� ����(��ȣ)" << std::endl;
		std::cout << "3. ��ü �л� ���" << std::endl;
		std::cout << "4. ���� �� ���" << std::endl;
		std::cout << "5. ��� �̻��� ���" << std::endl;
		std::cout << "6. ����" << std::endl;
		std::cout << "> ";

		int command{};
			std::cin >> command ;

			switch (command)
			{
			case 1: AddStudent(stdents_v);
				break;
			case 2: RemoveStudent(stdents_v);
				break;
			case 3: PrintStudents(stdents_v);
				break;
			case 4: PrintAverage(stdents_v);
				break;
			case 5: PrintOverAverage(stdents_v);
				break;
			case 6: 
				isQuit = true;
				break;
			default:
				std::cerr << "�߸��� ����Դϴ�." << std::endl;
				break;
			}
	}
}