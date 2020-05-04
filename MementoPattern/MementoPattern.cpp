// MementoPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "MementoPattern.h"

int main()
{
	Originator originator;
	originator.setState("#State 1");
	Memento *_Memento0 =  originator.saveStateToMemento();
	CareTaker::getInstance()->addMemento(_Memento0);

	originator.setState("#State 2");
	Memento *_Memento1 = originator.saveStateToMemento();
	CareTaker::getInstance()->addMemento(_Memento1);

	originator.setState("#State 3");
	Memento *_Memento2 = originator.saveStateToMemento();
	CareTaker::getInstance()->addMemento(_Memento2);

	cout << originator.getState() << endl;

	Memento* oldMemento = CareTaker::getInstance()->getMemento(0);
	originator.setStateFromMemento(oldMemento);
	cout << originator.getState() << endl;

	oldMemento = CareTaker::getInstance()->getMemento(1);
	originator.setStateFromMemento(oldMemento);
	cout << originator.getState() << endl;

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

CareTaker* CareTaker::getInstance()
{
	static CareTaker m_CareTaker;
	return &m_CareTaker;
}

void CareTaker::addMemento(Memento * _addMemento)
{
	if(_addMemento != nullptr)
		m_MementoList.push_back(_addMemento);
}

Memento * CareTaker::getMemento(int index)
{
	if(index <= m_MementoList.size() && m_MementoList.size() != 0)
		return m_MementoList[index];

	return nullptr;
}

Memento * Originator::saveStateToMemento()
{
	return new Memento(state);
}

string Originator::getState()
{
	return state;
}

void Originator::setStateFromMemento(Memento * _memento)
{
	if (_memento != nullptr)
	{
		state = _memento->GetState();
	}
}
