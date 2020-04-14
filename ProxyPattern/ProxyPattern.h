#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//����һ���ӿ�
class Image
{
public:
	virtual void display() = 0;
};

//����ʵ�ֽӿڵ�ʵ����
class RealImage : public Image
{
private:
	string fileName;
public:
	RealImage() {};
	RealImage(const string& _fileName)
		:fileName(_fileName)
	{
		loadFromDisk(_fileName);
	}
	virtual void display();
	void loadFromDisk(const string& _fileName);

};

class ProxyImage : public Image
{
private:
	string fileName;
	RealImage* realImage;
public:
	ProxyImage(const string& _fileName)
		:fileName(_fileName)
		, realImage(nullptr)
	{}

	virtual void display();
};