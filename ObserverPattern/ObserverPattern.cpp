// ObserverPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "ObserverPattern.h"

int main()
{
	Blog* blog = new BlogCSDN("CSND");
	Observer* observerBlog = new ObserverBlog("tutupig");
	observerBlog->AddBlog("CSND", blog);
	blog->AddObserver(observerBlog);
	blog->SetStatus("发表设计模式C++实现（15）——观察者模式");
	blog->Notify();
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

void Blog::AddObserver(Observer * _Observer)
{
	if (_Observer == nullptr)
		return;

	m_ObserverList.push_back(_Observer);
}

void Blog::RemoveObserver(Observer * _Observer)
{
	if (_Observer == nullptr)
		return;

	m_ObserverList.remove(_Observer);
}

void Blog::Notify()
{
	list<Observer*>::iterator iter = m_ObserverList.begin();
	while (iter != m_ObserverList.end())
	{
		(*iter)->Update(m_Name);
		iter++;
	}
}

void Blog::SetStatus(string _status)
{
	m_Status = _status;
}

string Blog::GetStatus()
{
	return m_Status;
}

void BlogCSDN::SetStatus(string _status)
{
	m_Status =  _status;
}

string BlogCSDN::GetStatus()
{
	return m_Name + m_Status;
}

void ObserverBlog::AddBlog(string _name, Blog* _blog)
{
	if (_blog == nullptr)
		return;

	m_BlogMap.insert(std::make_pair(_name, _blog));
}

void ObserverBlog::Update(string _name)
{
	map<string, Blog*>::iterator _iter = m_BlogMap.find(_name);
	if (_iter != m_BlogMap.end())
	{
		string status = _iter->second->GetStatus();
		cout << status << endl;
	}
}
