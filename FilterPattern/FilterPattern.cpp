// FilterPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "FilterPattern.h"

static void printPersons(std::vector<Person> persons);

int main()
{
	std::vector<Person> m_VecPerson;

	m_VecPerson.push_back( Person("Robert", "Male", "Single") );
	m_VecPerson.push_back( Person("John", "Male", "Married") );
	m_VecPerson.push_back( Person("Laura", "Female", "Married") );
	m_VecPerson.push_back( Person("Diana", "Female", "Single") );
	m_VecPerson.push_back( Person("Mike", "Male", "Single") );
	m_VecPerson.push_back( Person("Bobby", "Male", "Single") );

	Criteria *male = new CriteriaMale();
	Criteria *female = new CriteriaFemale();
	Criteria *single = new CriteriaSingle();
	Criteria *singleMale = new AndCriteria(*single, *male);
	Criteria *singleOrFemale = new OrCriteria(*single, *female);

	cout << "Males: ";
	printPersons(male->meetCriteria(m_VecPerson));

	cout << "\nFemales: ";
	printPersons(female->meetCriteria(m_VecPerson));

	cout << "\nSingle Males: ";
	printPersons(singleMale->meetCriteria(m_VecPerson));

	cout << "\nSingle Or Females: ";
	printPersons(singleOrFemale->meetCriteria(m_VecPerson));

}

static void printPersons(std::vector<Person> persons)
{
	for (Person person : persons)
	{
		cout << "Person : [ Name : " + person.GetName() + ", Gender : " + person.GetGender() + ", Marital Status : " + person.GetMaritalStatus()+ " ]" << endl;
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

Person::Person(string _name, string _gender, string _maritalStatus)
{
	name = _name;
	gender = _gender;
	maritalStatus = _maritalStatus;
}

std::vector<Person> CriteriaMale::meetCriteria(std::vector<Person> _VecPerson)
{
	std::vector<Person> malePersons;
	for (Person _person : _VecPerson)
	{
		if (_person.GetGender() == "Male")
		{
			malePersons.push_back(_person);
		}
	}
	return malePersons;
}

std::vector<Person> CriteriaFemale::meetCriteria(std::vector<Person> _VecPerson)
{
	std::vector<Person> femalePersons;
	for (Person _person : _VecPerson)
	{
		if (_person.GetGender() == "Female")
		{
			femalePersons.push_back(_person);
		}
	}
	return femalePersons;
}

std::vector<Person> CriteriaSingle::meetCriteria(std::vector<Person> _VecPerson)
{
	std::vector<Person> SinglePersons;
	for (Person _person : _VecPerson)
	{
		if (_person.GetMaritalStatus() == "Single")
		{
			SinglePersons.push_back(_person);
		}
	}
	return SinglePersons;
}

AndCriteria::AndCriteria(Criteria &_criteria, Criteria &_otherCriteria)
{
	criteria = &_criteria;
	otherCriteria = &_otherCriteria;
}

std::vector<Person> AndCriteria::meetCriteria(std::vector<Person> _VecPerson)
{
	std::vector<Person> firstPersons = criteria->meetCriteria(_VecPerson);
	return otherCriteria->meetCriteria(firstPersons);
}

OrCriteria::OrCriteria(Criteria & _criteria, Criteria & _otherCriteria)
{
	criteria = &_criteria;
	otherCriteria = &_otherCriteria;
}
std::vector<Person> OrCriteria::meetCriteria(std::vector<Person> _VecPerson)
{
	std::vector<Person> firstPersons = criteria->meetCriteria(_VecPerson);
	std::vector<Person> otherPersons = otherCriteria->meetCriteria(_VecPerson);
	std::vector<Person> outPersons;

	bool bFind = false;
	for (Person otherPerson : otherPersons)
	{

		for (Person firstPerson : firstPersons)
		{
			if (otherPerson.GetName() == firstPerson.GetName() && otherPerson.GetGender() == firstPerson.GetGender() && otherPerson.GetMaritalStatus() == firstPerson.GetMaritalStatus())
			{
				bFind = true;
				break;
			}
		}
		if(!bFind)
			outPersons.push_back(otherPerson);
	}

	return outPersons;
}
