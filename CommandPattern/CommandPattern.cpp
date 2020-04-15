#include "CommandPattern.h"
// CommandPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "CommandPattern.h"

int main()
{
	Stock abcStock;

	BuyStock buyStockOrder(abcStock);
	SellStock sellStockOrder(abcStock);

	Broker broker;
	broker.taskOrder(&buyStockOrder);
	broker.taskOrder(&sellStockOrder);

	broker.placeOrders();
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

Stock::Stock()
{
	name = "ABC";
	quantity = 10;
}

void Stock::buy()
{
	cout << "Stock [ Name: " + name + ", Quantity: " + to_string(quantity) + " ] bought" << endl;
}

void Stock::sell()
{
	cout << "Stock [ Name: " + name + ", Quantity: " + to_string(quantity) + " ] sold" << endl;
}

BuyStock::BuyStock(Stock & _stock)
{
	abcStock = &_stock;
}

void BuyStock::execute()
{
	if (abcStock)
	{
		abcStock->buy();
	}
}

SellStock::SellStock(Stock & _stock)
{
	abcStock = &_stock;
}

void SellStock::execute()
{
	if (abcStock)
	{
		abcStock->sell();
	}
}

void Broker::taskOrder(Order * _order)
{
	orderList.push_back(_order);
}

void Broker::placeOrders()
{
	for (Order* _order : orderList)
	{
		if (_order)
		{
			_order->execute();
		}
	}
	orderList.clear();
}
