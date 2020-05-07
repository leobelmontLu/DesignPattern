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
	virtual void Draw() { cout << "Draw Rectangle" << endl; };
};

class Circle : public Shape
{
public:
	virtual void Draw() { cout << "Draw Circle" << endl; };
};

class ShapeDecorator : public Shape
{
public:
	ShapeDecorator(Shape* _shape);
	virtual void Draw();
	virtual void setsetRedBorder() = 0;
protected:
	Shape* decoratedShape;
};

class RedShapeDecorator : public ShapeDecorator
{
public:
	RedShapeDecorator(Shape* _shape)
		:ShapeDecorator(_shape)
	{}

	virtual void Draw();
	virtual void setsetRedBorder();
};