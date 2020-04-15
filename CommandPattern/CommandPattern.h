#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//命令接口
class Order
{
public:
	virtual void execute() = 0;
};

//请求类
class Stock
{
public:
	Stock();
	void buy();
	void sell();
private:
	int quantity;
	string  name;
};
//命令接口实体类
class BuyStock : public Order
{
public:
	BuyStock(Stock& _stock);
	virtual void execute();
private:
	Stock* abcStock;
};
//命令接口实体类
class SellStock : public Order
{
public:
	SellStock(Stock& _stock);
	virtual void execute();
private:
	Stock* abcStock;
};

//命令调用类
class Broker
{
public:
	void taskOrder(Order* _order);
	void placeOrders();
private:
	list<Order*> orderList;
};