#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Strategy
{
public:
	virtual int doOperation(int num1, int num2) = 0;
};

class AddStrategy : public Strategy
{
public:
	virtual int doOperation(int num1, int num2);
};

class SubtractStrategy : public Strategy
{
public:
	virtual int doOperation(int num1, int num2);
};

class MultiplyStrategy : public Strategy
{
public:
	virtual int doOperation(int num1, int num2);
};

class ConText
{
public:
	void SetStrategy(Strategy* _pStrategy);
	int executeStrategy(int num1, int num2);
private:
	Strategy* m_pStrategy;
};