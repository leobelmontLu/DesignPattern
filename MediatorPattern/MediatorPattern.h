#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

class SmartDevice;

class SmartMediator
{
public:
	virtual void AddSmartDevice(SmartDevice* _SmartDevice) = 0;
	virtual void music(string instruction) = 0;
	virtual void curtain(string instruction) = 0;
	virtual void bath(string instruction) = 0;
protected:
	vector<SmartDevice*> SmartDeviceList;
};

class ConcreteMediator : public SmartMediator
{
public:
	virtual void AddSmartDevice(SmartDevice* _SmartDevice);
	virtual void music(string instruction);
	virtual void curtain(string instruction);
	virtual void bath(string instruction);
};

class SmartDevice
{
public:
	SmartDevice(string _deviceType,SmartMediator* _smartMediator)
		:deviceType(_deviceType)
		,smartMediator(_smartMediator)
	{}
	virtual void readyState(string instruction) = 0;
	virtual void operateDevice(string instruction) = 0;
	virtual string GetDeviceType() { return deviceType; };
protected:
	string deviceType;
	SmartMediator* smartMediator;
};

class MusicDevice : public SmartDevice
{
public:
	MusicDevice(string _deviceType, SmartMediator* _smartMediator)
		:SmartDevice(_deviceType, _smartMediator)
	{}
	virtual void readyState(string instruction);
	virtual void operateDevice(string instruction);
};

class CurtainDevice : public SmartDevice
{
public:
	CurtainDevice(string _deviceType, SmartMediator* _smartMediator)
		:SmartDevice(_deviceType, _smartMediator)
	{}
	virtual void readyState(string instruction);
	virtual void operateDevice(string instruction);
};

class BathDevice : public SmartDevice
{
public:
	BathDevice(string _deviceType, SmartMediator* _smartMediator)
		:SmartDevice(_deviceType, _smartMediator)
	{}
	virtual void readyState(string instruction);
	virtual void operateDevice(string instruction);
};