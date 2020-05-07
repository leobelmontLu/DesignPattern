// NullObjectPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "NullObjectPattern.h"

int main()
{
	CustomerFactory::AddCustomerName("Rob");
	CustomerFactory::AddCustomerName("Joe");
	CustomerFactory::AddCustomerName("Julie");

	AbstractCustomer* customer1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer* customer2 = CustomerFactory::getCustomer("Joe");
	AbstractCustomer* customer3 = CustomerFactory::getCustomer("Julie");
	AbstractCustomer* customer4 = CustomerFactory::getCustomer("Laura");

   cout << customer1->getName() << endl;
   cout << customer2->getName() << endl;
   cout << customer3->getName() << endl;
   cout << customer4->getName() << endl;
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

string RealCustomer::getName()
{
	return m_sName;
}

bool RealCustomer::isNil()
{
	return false;
}

string NullCustomer::getName()
{
	return "Not Available in Customer Database";
}

bool NullCustomer::isNil()
{
	return true;
}

AbstractCustomer * CustomerFactory::getCustomer(string _name)
{
	for (int i = 0; i < m_names.size();i++)
	{
		if (m_names[i] == _name)
		{
			return new RealCustomer(_name);
		}
	}

	return new NullCustomer();
}

void CustomerFactory::AddCustomerName(string _name)
{
	m_names.push_back(_name);
}
