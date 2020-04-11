#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Person
{
public:
	Person(string _name, string _gender, string _maritalStatus);
	string GetName() { return name; }
	string GetGender() { return gender; }
	string GetMaritalStatus() { return maritalStatus; }
private:
	string name;
	string gender;
	string maritalStatus;
};

class Criteria
{
public:
	std::vector<Person> m_VecPerson;
	virtual std::vector<Person> meetCriteria(std::vector<Person> _VecPerson) = 0;
};

class CriteriaMale : public Criteria
{
public:
	std::vector<Person> meetCriteria(std::vector<Person> _VecPerson);
};

class CriteriaFemale : public Criteria
{
public:
	std::vector<Person> meetCriteria(std::vector<Person> _VecPerson);
};

class CriteriaSingle : public Criteria
{
public:
	std::vector<Person> meetCriteria(std::vector<Person> _VecPerson);
};

class AndCriteria : public Criteria
{
public:
	AndCriteria(Criteria &criteria, Criteria &otherCriteria);
	std::vector<Person> meetCriteria(std::vector<Person> _VecPerson);
private:
	Criteria *criteria;
	Criteria *otherCriteria;
};
class OrCriteria : public Criteria
{
public:
	OrCriteria(Criteria &criteria, Criteria &otherCriteria);
	std::vector<Person> meetCriteria(std::vector<Person> _VecPerson);
private:
	Criteria *criteria;
	Criteria *otherCriteria;
};
