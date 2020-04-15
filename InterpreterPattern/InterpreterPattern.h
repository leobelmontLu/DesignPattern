#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Expression
{
public:
	virtual bool interpret(string& _text) = 0;
};

class TerminalExpression : public Expression
{
public:
	TerminalExpression(string &data);
	virtual bool interpret(string& _text);
private:
	string data;
};

class OrExpression : public Expression
{
public:
	OrExpression(Expression& _expr1, Expression& _expr2);
	virtual bool interpret(string& _text);
private:
	Expression* expr1;
	Expression* expr2;
};

class AndExpression : public Expression
{
public:
	AndExpression(Expression& _expr1, Expression& _expr2);
	virtual bool interpret(string& _text);
private:
	Expression* expr1;
	Expression* expr2;
};