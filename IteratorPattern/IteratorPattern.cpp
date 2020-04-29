// IteratorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "IteratorPattern.h"

int main()
{
	ConcreteAggregate<int> IntAggregate;
	Iterator<int>* iter =   IntAggregate.createIterator();
	iter->push_back(1);
	iter->push_back(3);
	iter->push_back(5);
	iter->push_back(7);
	iter->push_back(9);

	for (int i = 0; i < IntAggregate.getLen();i++)
	{
		cout << IntAggregate[i] << endl;
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

template<class T>
Iterator<T>* ConcreteAggregate<T>::createIterator()
{
	return new ConcreteIterator<T>(this);

}

template<class T>
T & ConcreteAggregate<T>::operator[](int index)
{
	// TODO: 在此处插入 return 语句

	return m_data[index];
}

template<class T>
int ConcreteAggregate<T>::getLen()
{
	return m_data.size();
}

template<class T>
void ConcreteAggregate<T>::push_back(T _data)
{
	m_data.push_back(_data);
}


template<class T>
void ConcreteIterator<T>::fist()
{
	index = 0;
}

template<class T>
void ConcreteIterator<T>::next()
{
	if (aggre)
	{
		if (index < aggre->getLen())
		{
			index++;
		}
	}
}

template<class T>
T * ConcreteIterator<T>::currentItem()
{
	if (aggre)
	{
		if (index <= aggre->getLen())
		{
			return &(*aggre)[index];
		}
	}
	return nullptr;
}

template<class T>
bool ConcreteIterator<T>::isDone()
{
	if (!aggre)
		return true;

	return (index >= aggre->getLen());
}

template<class T>
void ConcreteIterator<T>::push_back(T _data)
{
	if (aggre)
	{
		aggre->push_back(_data);
	}
}
