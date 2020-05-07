#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;


class AbstractCustomer
{
public:
	virtual string getName() = 0;
	virtual bool isNil() = 0;
protected:
	string m_sName;
};

class RealCustomer : public AbstractCustomer
{
public:
	RealCustomer(string _name)
	{
		m_sName = _name;
	}

	virtual string getName();
	virtual bool isNil();

};

class NullCustomer : public AbstractCustomer
{
public:
	virtual string getName();
	virtual bool isNil();
};

class CustomerFactory
{
public:
	static AbstractCustomer* getCustomer(string _name);
	static void AddCustomerName(string _name);
	static vector<string> m_names;
};
//初始化静态成员数组
vector<string> CustomerFactory::m_names;