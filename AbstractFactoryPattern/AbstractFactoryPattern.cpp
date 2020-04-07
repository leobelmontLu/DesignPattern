#include "pch.h"
#include "AbstractFactoryPattern.h"

Rectangle::Rectangle()
{

}
Rectangle::~Rectangle()
{

}
void Rectangle::draw()
{
	std::cout << "Inside Rectangle::draw()" << std::endl;
}


Square::Square()
{

}
Square::~Square()
{

}
void Square::draw()
{
	std::cout << "Inside Square::draw()" << std::endl;
}

Circle::Circle()
{

}
Circle::~Circle()
{

}
void Circle::draw()
{
	std::cout << "Inside Circle::draw()" << std::endl;
}

ShapeFactory::ShapeFactory()
{

}
ShapeFactory::~ShapeFactory()
{

}
Shape* ShapeFactory::getShape(const string& shapeType)
{
	if (shapeType == "")
		return nullptr;
	if (shapeType == "Rectangle")
	{
		return new Rectangle();
	}
	else if (shapeType == "Square")
	{
		return new Square();
	}
	else if (shapeType == "Circle")
	{
		return new Circle();
	}
	return nullptr;
}

AbstractFactory* FactoryProducer::getFactory(const string& factoryType)
{
	if (factoryType == "")
	{
		return nullptr;
	}

	if (factoryType == "Shape")
	{
		return new ShapeFactory();
	}
}

int main()
{
	//获取形状工厂
	AbstractFactory* shapeFactory = FactoryProducer::getFactory("Shape");
	if (shapeFactory)
	{
		Shape* square = shapeFactory->getShape("Square");
		if (square)
		{
			square->draw();
		}
		
		Shape* circle = shapeFactory->getShape("Circle");
		if (circle)
		{
			circle->draw();
		}
	}
}

