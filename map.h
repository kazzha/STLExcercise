#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <numeric>

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
	std::cout << "번호 이름 점수 : ";
	Student newStudent{};
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		/*for (const auto& e : v) // find 기능이 없어 만들어줘야함
		{
			if (e.mNumber == newStudent.mNumber) 
			{
				std::cout << "중복된 번호입니다" << std::endl;
				return;
			}
		}*/

		auto itr = std::find_if(v.begin(), v.end(), [&](const auto& e) 
			{return e.mNumber == newStudent.mNumber; });
		if (itr != v.end())
		{
			std::cout << "중복된 번호입니다." << std::endl;
			return;
		}
		v.push_back(newStudent);
	}
	else
	{
		std::cout << "잘못된 입력입니다." << std::endl;
	}
}

void RemoveStudent(std::vector<Student>& v)
{
	std::cout << "삭제할 번호를 입력하세요 : ";
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
		std::cout << "번호를 입력해 주세요" << std::endl;
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

	std::cout << "총점 : " << total << ", 평균 : " << total / v.size() << std::endl;

}
void PrintOverAverage(const std::vector<Student>& v)
{
	int total{};

	for (const auto& e : v)
	{
		total += e.mScore;
	}
	int average = total / static_cast<int>(v.size());
	/*for (const auto& e : v)
	{
		if (e.mScore >= average)
		{
			e.Print();
		}
	}*/
	std::for_each(v.begin(), v.end(), [&](const auto& e)
		{
		  if (e.mScore >= average)
		    {
			e.Print();
		    }
		});
}
void Ex4()
{
	/* {번호, 이름  점수} */
	std::vector<Student> stdents_v{
		{1, "Kim", 80},
		{2, "Lee", 20},
		{3, "Park", 40},
		{4, "Choi", 30}
	};


	bool isQuit{ false };

	while (!isQuit)
	{
		std::cout << "1. 학생 추가" << std::endl;
		std::cout << "2. 학생 제거(번호)" << std::endl;
		std::cout << "3. 전체 학생 출력" << std::endl;
		std::cout << "4. 총점 및 평균" << std::endl;
		std::cout << "5. 평균 이상의 목록" << std::endl;
		std::cout << "6. 종료" << std::endl;
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
				std::cerr << "잘못된 명령입니다." << std::endl;
				break;
			}
	}
}

std::ostream& operator << (std::ostream& os, const Student& s)
{
	os << "[" << s.mNumber << "]" <<
		s.mName << " : " << s.mScore << std::endl;

	return os;
}

void AddStudent(std::map<int, Student>& m)
{
	std::cout << "번호 이름 점수 :";

	Student newStudent;
	if (std::cin >> newStudent.mNumber >> newStudent.mName >> newStudent.mScore)
	{
		auto result =  m.insert({ newStudent.mNumber, newStudent });
		// auto = std::pair<std::map<int,Student>::iterator,bool>

		if (!result.second)
		{
			std::cout << "중복된 학생 번호입니다." << std::endl;
			return;
		}
	}
	else
	{
		std::cerr << "잘못된 입력입니다.";
	}
}

void RemoveStudent(std::map<int, Student>& m)
{
	std::cout << "삭제할 번호를 입력하세요 : ";
	int number;
	if (std::cin >> number)
	{
		m.erase(number);
	}
	else
	{
		std::cout << "잘못된 입력입니다.";
	}
}

void PrintStudents(std::map<int, Student>& m)
{
	for (const auto& e : m)
	{
		std::cout << e.second << std::endl;
	}
}

void PrintAverage(std::map<int, Student>& m)
{
	int total{};

	total = std::accumulate(m.begin(), m.end(), 0, [](int accum, const auto& pair) {
		return accum += pair.second.mScore; }
	);
	std::cout << "총점: " << total << ", 평균: " << total / m.size() << std::endl;
}

void PrintOverAverage(std::map<int, Student>& m)
{
	int average{};

	average = std::accumulate(m.begin(), m.end(), 0, [](int accum, const auto& pair) {
		return accum += pair.second.mScore; }
	);

	average /= m.size();

	std::for_each(m.begin(), m.end(), [&](const auto& pair) {
		if (pair.second.mScore >= average)
		{
			std::cout << pair.second << std::endl;
		}
		});

}
void Ex4_Map()
{
	std::map<int, Student> students
	{
		{1,{1, "Kim", 80}},
		{2,{2, "Lee", 20}},
		{3,{3, "Park", 40}},
		{4,{4, "Choi", 30}}
	};
	

	bool isQuit{ false };

	while (!isQuit)
	{
		std::cout << "1. 학생 추가" << std::endl;
		std::cout << "2. 학생 제거(번호)" << std::endl;
		std::cout << "3. 전체 학생 출력" << std::endl;
		std::cout << "4. 총점 및 평균" << std::endl;
		std::cout << "5. 평균 이상의 목록" << std::endl;
		std::cout << "6. 종료" << std::endl;
		std::cout << "> ";

		int command{};
		std::cin >> command;

		switch (command)
		{
		case 1: AddStudent(students);
			break;
		case 2: RemoveStudent(students);
			break;
		case 3: PrintStudents(students);
			break;
		case 4: PrintAverage(students);
			break;
		case 5: PrintOverAverage(students);
			break;
		case 6:
			isQuit = true;
			break;
		default:
			std::cerr << "잘못된 명령입니다." << std::endl;
			break;
		}
	}
}