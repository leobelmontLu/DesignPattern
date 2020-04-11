#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;


class Employee
{
public:
	Employee(string _name, string _dept, int _salary);
	bool operator() (Employee &obj1);
	void add(Employee e);
	void remove(Employee e);
	std::list<Employee> getsubordinates();
	string toString();
private:
	string name;
	string dept;
	int salary;
	std::list<Employee> m_subordinates;
};