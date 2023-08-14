#pragma once

#include <iostream>
#include <array>
#include <forward_list>
#include <list>
#include <deque>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <set>

void Array()
{
	std::array<int, 4> myArray{ 1,2,3,4 };

	for (const auto& e : myArray)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	for (auto itr = myArray.begin(); itr != myArray.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << std::endl;
}

void ForwardListEx()
{
	std::forward_list<int> list{ 10, 11, 1, 2 };

	list.push_front(1);
	list.pop_front();

	list.sort();
	for (const auto& e : list)
	{
		std::cout << e << " ";
	}  // 는 가능
	std::cout << std::endl;
}

void ListEx()
{
	std::list<int> list{ 10, 11, 1, 2 };

}

void DequeEx()
{
	std::deque<int> deq{ 3,4,5 };
	deq.push_front(1);
	deq.push_back(6);

	deq.pop_back();
	deq.pop_front();

	std::sort(deq.begin(), deq.end());
}

void StackAndQueue()
{
	std::stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);

	std::stack<int> temp(s);
	while (!temp.empty())
	{
		std::cout << temp.top() << std::endl;
		temp.pop();
	}

	std::queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);
	
	q.pop();

	std::queue<int> temp2(q);
	while (!temp2.empty())
	{
		std::cout << temp2.front() << " ";
		temp2.pop();
	}
	std::cout << std::endl;

	std::priority_queue<int> pq;

	pq.push(3);
	pq.push(6);
	pq.push(1);

	std::priority_queue<int> temp3(pq);
	while (!temp3.empty())
	{
		std::cout << temp3.top() << " ";
		temp3.pop();
	}

	std::cout << std::endl; 

	struct App
	{
		int priority;
		std::string name;

		bool operator < (const App& app) const
		{
			return this->priority < app.priority;
		}
	};

	std::priority_queue<App> appQueue;
	appQueue.push({ 1, "notepad" });
	appQueue.push({ 5,"vscode" });
	appQueue.push({ 3, "Calendar" });

	std::cout << appQueue.top().name << std::endl;
}

void SetEx()
{
	std::set<int> s;

	s.insert(1);
	s.insert(6);
	s.insert(2);
	s.insert(5);

	for (auto e : s)
	{
		std::cout << e << std::endl;
	}

	std::unordered_set<int> us;
}

void MapEx()
{
	std::map<std::string, std::string> operators;

	operators.insert({ "+","더하기 연산자이면서 이항연산자입니다" });
	operators.insert({ ">>","비트 시프트 연산자입니다." });
	operators.insert({ "new","동적 메모리 할당 연산자입니다. delete 주의하세요" });

	std::cout << operators["+"] << std::endl;
}
void Ex3()
{
	StackAndQueue();
}