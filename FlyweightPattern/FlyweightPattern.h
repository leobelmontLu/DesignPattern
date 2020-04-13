#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class Shape
{
public:
	virtual void draw() = 0;
};

class Circle : public Shape
{
public:
	Circle() {};
	Circle(string _color,int _x,int _y,int _radius)
		:m_color(_color)
		,x(_x)
		,y(_y)
		,radius(_radius)
	{}

	void SetX(int _x) { x = _x; }
	void SetY(int _y) { y = _y; }
	void SetRadius(int _radius) { radius = _radius; }

	virtual void draw();
private:
	string m_color;
	int x;
	int y;
	int radius;
};

class ShapeFactory
{
public:
	static ShapeFactory& getInstance();
	Circle getCircle(const string& color);
private:
	ShapeFactory() {};
	ShapeFactory(const ShapeFactory&);
	std::unordered_map<string, Circle> circleMap;
};