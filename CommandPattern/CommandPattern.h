#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>

using namespace std;

//����ӿ�
class Order
{
public:
	virtual void execute() = 0;
};

//������
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
//����ӿ�ʵ����
class BuyStock : public Order
{
public:
	BuyStock(Stock& _stock);
	virtual void execute();
private:
	Stock* abcStock;
};
//����ӿ�ʵ����
class SellStock : public Order
{
public:
	SellStock(Stock& _stock);
	virtual void execute();
private:
	Stock* abcStock;
};

//���������
class Broker
{
public:
	void taskOrder(Order* _order);
	void placeOrders();
private:
	list<Order*> orderList;
};