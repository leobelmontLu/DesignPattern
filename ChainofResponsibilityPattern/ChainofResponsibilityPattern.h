#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;


static int INFO = 1;
static int DEBUG = 2;
static int ERROR = 3;

//创建抽象的记录器类
class AbstractLogger
{
public:
	AbstractLogger() {};
	void setNextAbstractLogger(AbstractLogger& _nextAbstractLogger);
	virtual void write(string message) = 0;
	void logMessage(int _level, string _message);
protected:
	int level;
	AbstractLogger* nextAbstractLogger;
};

//创建扩展了该记录器类的实体类
class ConsoleLogger : public AbstractLogger
{
public:
	ConsoleLogger(int _level);
	virtual void write(string message);
};

class ErrorLogger : public AbstractLogger
{
public:
	ErrorLogger(int _level);
	virtual void write(string message);
};

class FileLogger : public AbstractLogger
{
public:
	FileLogger(int _level);
	virtual void write(string message);
};