#pragma once
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
	virtual Shape* clone() = 0;

	string getID()
	{
		return id;
	}
	string getType()
	{
		return type;
	}
	void setId(const string& _id)
	{
		id = _id;
	}

protected:
	string type;
private:
	string id;

};

class Rectangle : public Shape
{
public:
	Rectangle();
	~Rectangle();

	virtual void draw();
	virtual Shape* clone();
};

class Square : public Shape
{
public:
	Square();
	~Square();

	virtual void draw();
	virtual Shape* clone();
};

class Circle : public Shape
{
public:
	Circle();
	~Circle();

	virtual void draw();
	virtual Shape* clone();
};


class ShapeCache
{
private:
	static std::map<string, Shape*> shapeMap;
	static int id;
public:
	static Shape* getShape(const string& shapeId);
	static bool LoadCache();
	static int GetId();
};