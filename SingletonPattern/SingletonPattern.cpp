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

