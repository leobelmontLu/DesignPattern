#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Context;

class State
{
public:
	State() {};
	virtual ~State() {};
	virtual void doAction(Context* _context) = 0;
private:
};

class ConcreteStateA : public State
{
public:
	ConcreteStateA() {};
	~ConcreteStateA() {};
	virtual void doAction(Context* _context);
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB() {};
	~ConcreteStateB() {};
	virtual void doAction(Context* _context);
};



class Context
{
public:
	Context() 
		:m_pState(nullptr)
	{};
	virtual~Context() {};
	virtual void Request();
	virtual void ChangeState(State* _state);
private:
	State* m_pState;
};

