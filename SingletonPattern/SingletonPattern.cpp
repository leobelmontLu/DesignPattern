#include "SingletonPattern.h"

template<typename T>
T& SingletonTObject<T>::getInstance()
{
	static T instance;
	return instance;
}

void QMManager::ShowMessage()
{
	std::cout << "QMManager::ShowMessage" << std::endl;
}

SingletonObject* SingletonObject::getInstance()
{
	std::unique_lock<std::mutex> lock(m_Mutex); // 加锁（在C++11中这里不需要再加锁了，因为C++11中局部静态变量是唯一的）
	static SingletonObject instance;
	return &instance;
}

void SingletonObject::ShowMessage()
{
	std::cout << "SingletonObject::ShowMessage" << std::endl;
}

int main()
{
	SingletonTObject<QMManager>::getInstance().ShowMessage();

	SingletonObject::getInstance()->ShowMessage();
}

