#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

//食物包装
class Packing
{
public:
	Packing() {};
	~Packing() {};
	virtual string pack() = 0;
};
//包装类实现
class Wrapper : public Packing
{
public:
	Wrapper() {};
	~Wrapper() {};
	virtual string pack()
	{
		return "Wrapper";
	}
};

class Bottle : public Packing
{
public:
	Bottle() {};
	~Bottle() {};
	virtual string pack()
	{
		return "Bottle";
	}
};

//食物条目
class  Item
{
public:
	Item() {};
	~Item() {};
	virtual string GetItemName() = 0;
	virtual Packing* GetPacking() = 0;
	virtual float price() = 0;
};
//食品条目实现
class Burger : public Item
{
public:
	Burger() {};
	~Burger() {};

	virtual string GetItemName() = 0;
	virtual Packing* GetPacking()
	{
		return new Wrapper();
	}
	virtual float price() = 0;
};

class ColdDrink : public Item
{
public:
	ColdDrink() {};
	~ColdDrink() {};

	virtual string GetItemName() = 0;
	virtual Packing* GetPacking()
	{
		return new Bottle();
	}
	virtual float price() = 0;
};

class VegBurger : public Burger
{
public:
	VegBurger() {};
	~VegBurger() {};

	virtual string GetItemName()
	{
		return "Veg Burger";
	}

	virtual float price()
	{
		return 25.0f;
	}
};

class ChickenBurger : public Burger
{
public:
	ChickenBurger() {};
	~ChickenBurger() {};

	virtual string GetItemName()
	{
		return "Chicken Burger";
	}

	virtual float price()
	{
		return 50.5f;
	}
};

class Coke : public ColdDrink
{
public:
	Coke() {};
	~Coke() {};

	virtual string GetItemName()
	{
		return "Coke";
	}

	virtual float price()
	{
		return 30.0f;
	}
};

class Pepsi : public ColdDrink
{
public:
	Pepsi() {};
	~Pepsi() {};

	virtual string GetItemName()
	{
		return "Pepsi";
	}

	virtual float price()
	{
		return 35.5f;
	}
};

typedef list<Item*> ItemList;
class Meal
{
public:
	Meal() {};
	~Meal() {};
	void addItem(Item* item);
	float getCost();
	void showItems();

private:
	ItemList itemList;
};


class MealBuilder
{
public:
	MealBuilder() {};
	~MealBuilder() {};

	bool prepareVegMeal(Meal& meal);
	bool prepareNonVegMeal(Meal& meal);

};