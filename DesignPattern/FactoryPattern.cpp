#include "FactoryPattern.h"



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

int main()
{
	ShapeFactory factory;
	Shape* shape = nullptr;
	shape = factory.getShape("Square");
	if (shape)
	{
		shape->draw();
	}
}

