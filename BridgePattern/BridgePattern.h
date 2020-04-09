#pragma once

#include <string>
#include <iostream>

using namespace std;

class DrawAPI
{
public:
	virtual void drawCircle(int radius, int x, int y) = 0;
};

class RedCircle : public DrawAPI
{
public:
	virtual void drawCircle(int radius, int x, int y);
};

class GreenCircle : public DrawAPI
{
public:
	virtual void drawCircle(int radius, int x, int y);
};

class Shape
{
protected:
	DrawAPI* drawAPI;
	Shape(DrawAPI* drawAPI) {
		this->drawAPI = drawAPI;
	}
public:
	virtual void draw() = 0;
};


class Circle : public Shape
{
private:
	int x;
	int y;
	int radius;

public:
	Circle(int _x, int _y, int _radius, DrawAPI* _drawAPI)
		:Shape(_drawAPI),
		x(_x),
		y(_y),
		radius(_radius)
	{
	}
	virtual void draw();
};