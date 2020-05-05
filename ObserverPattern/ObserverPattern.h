#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//观察者基类
class Blog;

class Observer
{
public:
	Observer() {};
	virtual ~Observer() {};
	virtual void AddBlog(string _name, Blog* _blog) {};
	virtual void Update(string _name) {};
};

class Blog
{
public:
	Blog(string _name) 
		:m_Name(_name)
	{}
	virtual ~Blog() {};
	void AddObserver(Observer *_Observer);
	void RemoveObserver(Observer *_Observer);
	void Notify();

	virtual void SetStatus(string _status);
	virtual string GetStatus();
protected:
	string m_Status;
	string m_Name;
private:
	list<Observer*> m_ObserverList;
};


class BlogCSDN : public Blog
{
public:
	BlogCSDN(string _name)
		:Blog(_name)
	{}
	~BlogCSDN()
	{

	}
	virtual void SetStatus(string _status);
	virtual string GetStatus();
};

class ObserverBlog : public Observer
{
public:
	ObserverBlog(string _name)
		:m_Name(_name)
	{}
	~ObserverBlog() {};
	virtual void AddBlog(string _name,Blog* _blog);
	virtual void Update(string _name);
private:
	string m_Name;
	map<string,Blog*> m_BlogMap;
};