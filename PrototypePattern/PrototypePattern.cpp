#include "PrototypePattern.h"
//初始化静态成员数组
std::map<string, Shape*> ShapeCache::shapeMap;
//初始化静态成员变量
int ShapeCache::id = 1;

Rectangle::Rectangle()
{
	type = "Rectangle";
}
Rectangle::~Rectangle()
{

}
void Rectangle::draw()
{
	cout << "Inside Rectangle::draw() method" << endl;
}

Shape* Rectangle::clone()
{
	return new Rectangle(*this);
}

Square::Square()
{
	type = "Square";
}
Square::~Square()
{

}
void Square::draw()
{
	cout << "Inside Square::draw() method" << endl;
}

Shape* Square::clone()
{
	return new Square(*this);
}

Circle::Circle()
{
	type = "Circle";
}
Circle::~Circle()
{

}
void Circle::draw()
{
	cout << "Inside Circle::draw() method" << endl;
}

Shape* Circle::clone()
{
	return new Circle(*this);
}


bool ShapeCache::LoadCache()
{
	Rectangle* rectangle = new Rectangle();
	rectangle->setId("1");
	shapeMap.insert(std::make_pair(rectangle->getID(), rectangle));

	Square* square = new Square();
	square->setId("2");
	shapeMap.insert(std::make_pair(square->getID(), square));

	Circle* circle = new Circle();
	circle->setId("3");
	shapeMap.insert(std::make_pair(circle->getID(), circle));
	return true;
}

Shape* ShapeCache::getShape(const string& shapeId)
{
	std::map<string, Shape*>::iterator iter = shapeMap.find(shapeId);
	if (iter != shapeMap.end() && iter->second)
	{
		return (iter->second)->clone();
	}
	return nullptr;
}

int ShapeCache::GetId()
{
	return id;
}

int main()
{
	ShapeCache::LoadCache();
	cout << ShapeCache::GetId() << endl;

	Shape* copyRectangle = ShapeCache::getShape("1");
	cout << copyRectangle->getType() << endl;
	
	Shape* copySquare = ShapeCache::getShape("2");
	cout << copySquare->getType() << endl;

	Shape* copyCircle = ShapeCache::getShape("3");
	cout << copyCircle->getType() << endl;

}
