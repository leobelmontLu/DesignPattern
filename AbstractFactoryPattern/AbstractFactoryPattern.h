#pragma once
#include <iostream>
#include <string>

using namespace std;

//���󲿷�
class Shape
{
public:
	Shape() {};
	virtual ~Shape() {};
	virtual void draw() = 0;
};

class Rectangle : public Shape
{
public:
	Rectangle();
	~Rectangle();
	virtual void draw();
};

class Square : public Shape
{
public:
	Square();
	~Square();
	virtual void draw();
};

class Circle : public Shape
{
public:
	Circle();
	~Circle();
	virtual void draw();
};


//��������
class AbstractFactory
{
public:
	AbstractFactory() {};
	~AbstractFactory() {};
	virtual Shape* getShape(const string& shapeType) = 0;
};
class ShapeFactory : public AbstractFactory
{
public:
	ShapeFactory();
	~ShapeFactory();

	Shape* getShape(const string& shapeType);
};

//����������
class FactoryProducer
{
public:
	static AbstractFactory* getFactory(const string& factoryType);
};