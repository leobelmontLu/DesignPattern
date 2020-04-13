#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

class Shape
{
public:
	virtual void Draw() = 0;
};


class Rectangle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "Shape: Rectangle" << endl;
	}
};

class Circle : public Shape
{
public:
	virtual void Draw()
	{
		cout << "Shape: Circle" << endl;
	}
};

class Square : public Shape
{
public:
	virtual void Draw();
};

class ShapeMaker
{
public:
	ShapeMaker();
	void drawSquare();
	void drawRectangle();
	void drawCircle();
protected:
	Shape* m_rectangle;
	Shape* m_circle;
	Shape* m_square;
};