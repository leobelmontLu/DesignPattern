#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//迭代器接口
template<class T>
class Iterator
{
public:
	virtual ~Iterator() {};
	virtual void fist() = 0;
	virtual void next() = 0;
	virtual T* currentItem() = 0;
	virtual bool isDone() = 0;
	virtual void push_back(T _data) = 0;
};

//容器接口
template<class T>
class Aggregate
{
public:
	virtual Iterator<T>* createIterator() = 0;
	virtual ~Aggregate() {};
};

//容器实例
template<class T>
class ConcreteAggregate : public Aggregate<T>
{
public:
	virtual Iterator<T>* createIterator();
	T& operator[](int index);
	int getLen();
	virtual void push_back(T _data);
private:
	vector<T> m_data;
};

//迭代器实例
template<class T>
class ConcreteIterator : public Iterator<T>
{
public:
	ConcreteIterator(ConcreteAggregate<T>* _aggre)
		:aggre(_aggre)
		,index(0)
	{}

	virtual void fist();
	virtual void next();
	virtual T* currentItem();
	virtual bool isDone();
	void push_back(T _data);
private:
	ConcreteAggregate<T>* aggre;
	int index;
};