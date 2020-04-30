// MediatorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "MediatorPattern.h"

int main()
{
	SmartMediator* _SmartMediator = new ConcreteMediator();

	SmartDevice* musicDevice = new MusicDevice("music", _SmartMediator);
	SmartDevice* curtainDevice = new CurtainDevice("curtain", _SmartMediator);
	SmartDevice* bathDevice = new BathDevice("bath", _SmartMediator);

	if (_SmartMediator)
	{
		_SmartMediator->AddSmartDevice(musicDevice);
		_SmartMediator->AddSmartDevice(curtainDevice);
		_SmartMediator->AddSmartDevice(bathDevice);

		musicDevice->operateDevice("open");
		bathDevice->operateDevice("close");
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

void MusicDevice::readyState(string instruction)
{
	cout << "音响设备准备"<< instruction << endl;
}

void MusicDevice::operateDevice(string instruction)
{
	cout << "音响设备已"<< instruction << endl;

	if(smartMediator)
		smartMediator->music(instruction);
}

void CurtainDevice::readyState(string instruction)
{
	cout << "窗帘设备准备" << instruction << endl;
}

void CurtainDevice::operateDevice(string instruction)
{
	cout << "窗帘设备已" << instruction << endl;

	if (smartMediator)
		smartMediator->curtain(instruction);
}

void BathDevice::readyState(string instruction)
{
	cout << "淋浴设备准备" << instruction << endl;
}

void BathDevice::operateDevice(string instruction)
{
	cout << "淋浴设备已" << instruction << endl;
	if (smartMediator)
	{
		smartMediator->bath(instruction);
	}
}

void ConcreteMediator::AddSmartDevice(SmartDevice * _SmartDevice)
{
	SmartDeviceList.push_back(_SmartDevice);
}

void ConcreteMediator::music(string instruction)
{
	for (int i = 0; i < SmartDeviceList.size(); i++)
	{
		if (SmartDeviceList[i]->GetDeviceType() != "music")
		{
			SmartDeviceList[i]->readyState(instruction);
		}
	}
}

void ConcreteMediator::curtain(string instruction)
{
	for (int i = 0; i < SmartDeviceList.size(); i++)
	{
		if (SmartDeviceList[i]->GetDeviceType() != "curtain")
		{
			SmartDeviceList[i]->readyState(instruction);
		}
	}
}

void ConcreteMediator::bath(string instruction)
{
	for (int i = 0; i < SmartDeviceList.size(); i++)
	{
		if (SmartDeviceList[i]->GetDeviceType() != "bath")
		{
			SmartDeviceList[i]->readyState(instruction);
		}
	}
}
