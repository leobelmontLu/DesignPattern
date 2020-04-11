// CompositePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "CompositePattern.h"

int main()
{
	Employee CEO("John", "CEO", 30000);

	Employee headSales("Robert", "Head Sales", 20000);

	Employee headMarketing("Michel", "Head Marketing", 20000);

	Employee clerk1("Laura", "Marketing", 10000);
	Employee clerk2("Bob", "Marketing", 10000);

	Employee salesExecutive1("Richard", "Sales", 10000);
	Employee salesExecutive2("Rob", "Sales", 10000);

	headSales.add(salesExecutive1);
	headSales.add(salesExecutive2);

	headMarketing.add(clerk1);
	headMarketing.add(clerk2);

	CEO.add(headSales);
	CEO.add(headMarketing);

	//打印该组织的所有员工
	cout << CEO.toString() << endl;
	for (Employee headEmployee : CEO.getsubordinates()) {
		cout << headEmployee.toString() << endl;
		for (Employee employee : headEmployee.getsubordinates()) {
			cout  << employee.toString() << endl;
		}
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

Employee::Employee(string _name, string _dept, int _salary)
{
	name = _name;
	dept = _dept;
	salary = _salary;
}

bool Employee::operator()(Employee & obj1)
{
	if (this->name == obj1.name)
	{
		return true;
	}
	return false;
}

void Employee::add(Employee e)
{
	m_subordinates.push_back(e);
}

void Employee::remove(Employee e)
{
	m_subordinates.remove_if(e);
}

std::list<Employee> Employee::getsubordinates()
{
	return m_subordinates;
}

string Employee::toString()
{
	return ("Employee :[ Name : " + name + ", dept : " + dept + ", salary :" + std::to_string(salary) + " ]");
}
