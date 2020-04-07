#pragma once
#include <iostream>

//单例模板
template<typename T>
class SingletonTObject
{
protected:
	SingletonTObject() {};
private:
	SingletonTObject(const SingletonTObject& s) {};
	SingletonTObject& operator = (SingletonTObject& s) {};
public:
	virtual ~SingletonTObject() {};
	static T& getInstance();
};


class QMManager : public SingletonTObject<QMManager>
{
private:
	QMManager() {};
	~QMManager() {};
	friend class SingletonTObject<QMManager>;
public:
	void ShowMessage();
};


//单利类
class SingletonObject
{
private:
	SingletonObject() {};
	~SingletonObject() {};
public:
	static SingletonObject* getInstance();
	virtual void ShowMessage();
};