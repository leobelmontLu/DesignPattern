#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Memento
{
public:
	Memento(const string& _state)
		:state(_state)
	{}
	string& GetState() { return state; }
private:
	string state;
};

class Originator
{
public:
	void setState(const string& _state) { state = _state; }
	Memento* saveStateToMemento();
	string getState();
	void setStateFromMemento(Memento* _memento);
private:
	string state;
};

class CareTaker
{
public:
	static CareTaker* getInstance();
	void addMemento(Memento* _addMemento);
	Memento* getMemento(int index);
private:
	CareTaker() {};
	CareTaker(const CareTaker& _careTaker) {};
	vector<Memento*> m_MementoList;
};