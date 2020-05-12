// VisitorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "VisitorPattern.h"

int main()
{
	ComputerPart* _ComputerPart = new Computer();
	ComputerPartVisitor* _ComputerPartVisitor = new ComputerPartDisplayVisitor();

	if(_ComputerPart && _ComputerPartVisitor)
		_ComputerPart->accept(_ComputerPartVisitor);
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

void Keyboard::accept(ComputerPartVisitor * _ComputerPartVisitor)
{
	if (_ComputerPartVisitor)
	{
		_ComputerPartVisitor->visit(this);
	}
}

void Mouse::accept(ComputerPartVisitor * _ComputerPartVisitor)
{
	if (_ComputerPartVisitor)
	{
		_ComputerPartVisitor->visit(this);
	}
}

void Monitor::accept(ComputerPartVisitor * _ComputerPartVisitor)
{
	if (_ComputerPartVisitor)
	{
		_ComputerPartVisitor->visit(this);
	}
}

Computer::Computer()
{
	ComputerPart *keyboard = new Keyboard();
	m_parts.push_back(keyboard);

	ComputerPart *mouse = new Mouse();
	m_parts.push_back(mouse);

	ComputerPart *monitor = new Monitor();
	m_parts.push_back(monitor);
}

void Computer::accept(ComputerPartVisitor * _ComputerPartVisitor)
{
	for (int i = 0; i < m_parts.size();i++)
	{
		if (m_parts[i])
		{
			m_parts[i]->accept(_ComputerPartVisitor);
		}
	}

	if (_ComputerPartVisitor)
	{
		_ComputerPartVisitor->visit(this);
	}
}

void ComputerPartDisplayVisitor::visit(Keyboard * keyboard)
{
	printf("%s\n", "Displaying Keyboard!");
}

void ComputerPartDisplayVisitor::visit(Mouse * Keyboard)
{
	printf("%s\n", "Displaying Mouse!");
}

void ComputerPartDisplayVisitor::visit(Monitor *monitor)
{
	printf("%s\n", "Displaying Monitor!");
}

void ComputerPartDisplayVisitor::visit(Computer * computer)
{
	printf("%s\n", "Displaying Computer!");
}
