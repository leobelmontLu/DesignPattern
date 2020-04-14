#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//创建一个接口
class Image
{
public:
	virtual void display() = 0;
};

//创建实现接口的实体类
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