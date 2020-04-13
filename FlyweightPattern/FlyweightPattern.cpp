// FlyweightPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "FlyweightPattern.h"
#include <stdlib.h>

string Colors[] = { "Red","Blue","Green","White","Black" };

int getRandomColor()
{
	return rand() % Colors->length();
}
int main()
{
    for (int i = 0; i < 20;i++)
    {
		Circle _circle = ShapeFactory::getInstance().getCircle(Colors[getRandomColor()]);
		_circle.SetX(rand() * 100);
		_circle.SetY(rand() * 100);
		_circle.SetRadius(100);
		_circle.draw();
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件

void Circle::draw()
{
	cout << "Circle: Draw() [Color : " + m_color + ", x : " + to_string(x) + ", y :" + to_string(y) + ", radius :" + to_string(radius) << endl;
}

ShapeFactory& ShapeFactory::getInstance()
{
	static ShapeFactory shapeFactory;
	return shapeFactory;
}

Circle ShapeFactory::getCircle(const string & color)
{
	Circle _circle;
	std::unordered_map<string, Circle>::iterator iter = circleMap.find(color);
	if (iter != circleMap.end())
	{
		_circle =  iter->second;
	}
	else
	{
		_circle = Circle(color,0,0,0);
		circleMap.insert( std::make_pair(color, _circle));
		cout << "Creating circle of color : " + color << endl;
	}
	return _circle;
}

ShapeFactory::ShapeFactory(const ShapeFactory &)
{
}
