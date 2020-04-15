// InterpreterPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "InterpreterPattern.h"


   //规则：Robert 和 John 是男性
static Expression* getMaleExpression()
{
	string name = string("Robert");
	string name1 = string("John");
	Expression* robert = new TerminalExpression(name);
	Expression* john = new TerminalExpression(name1);
	return new OrExpression(*robert, *john);
}

//规则：Julie 是一个已婚的女性
static Expression* getMarriedWomanExpression() 
{
	string name = string("Julie");
	string name1 = string("Married");
	Expression* julie = new TerminalExpression(name);
	Expression* married = new TerminalExpression(name1);
	return new AndExpression(*julie, *married);
}

int main()
{
	Expression* isMale = getMaleExpression();
	Expression* isMarriedWoman = getMarriedWomanExpression();

	string name = string("John");
	string name1 = string("Married Julie");

	cout << "John is male? " + isMale->interpret(name) << endl;

	cout << "Julie is a married women? "+ isMarriedWoman->interpret(name1) << endl;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

TerminalExpression::TerminalExpression(string & data)
{
	this->data = data;
}

bool TerminalExpression::interpret(string & _text)
{
	size_t index = data.find(_text);
	if (index != -1)
		return true;

	return false;
}

OrExpression::OrExpression(Expression & _expr1, Expression & _expr2)
{
	this->expr1 = &_expr1;
	this->expr2 = &_expr2;

}

bool OrExpression::interpret(string & _text)
{
	if (expr1 && expr2)
	{
		return (expr1->interpret(_text) || expr2->interpret(_text));
	}
	return false;
}

AndExpression::AndExpression(Expression & _expr1, Expression & _expr2)
{
	this->expr1 = &_expr1;
	this->expr2 = &_expr2;
}

bool AndExpression::interpret(string & _text)
{
	if (expr1 && expr2)
	{
		return (expr1->interpret(_text) && expr2->interpret(_text));
	}
	return false;
}
