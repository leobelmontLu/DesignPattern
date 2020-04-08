#include "BuilderPattern.h"


void Meal::addItem(Item* item)
{
	if (item)
	{
		itemList.push_back(item);
	}
}

float Meal::getCost()
{
	float cost = 0.0f;
	ItemList::iterator iter = itemList.begin();
	for (; iter != itemList.end(); iter++)
	{
		cost += (*iter)->price();
	}
	return cost;
}

void Meal::showItems()
{
	ItemList::iterator iter = itemList.begin();
	for (; iter != itemList.end(); iter++)
	{
		cout << "Item : " << (*iter)->GetItemName() << ", Packing : " << (*iter)->GetPacking()->pack() << ", Price : " << (*iter)->price() << endl;
	}
}

bool MealBuilder::prepareVegMeal(Meal& meal)
{
	meal.addItem(new VegBurger());
	meal.addItem(new Coke());
	return true;
}

bool MealBuilder::prepareNonVegMeal(Meal& meal)
{
	meal.addItem(new ChickenBurger());
	meal.addItem(new Pepsi());
	return true;
}

int main()
{
	MealBuilder mealBuilder;

	Meal vegMeal;
	if (mealBuilder.prepareNonVegMeal(vegMeal))
	{
		cout << "Veg Meal" << endl;
		vegMeal.showItems();
		cout << "Total Cost:" << vegMeal.getCost() << endl;
	}
	cout << "\n" << endl;
	Meal nonVegMeal;
	if (mealBuilder.prepareNonVegMeal(nonVegMeal))
	{
		cout << "Non Veg Meal" << endl;
		nonVegMeal.showItems();
		cout << "Total Cost:" << nonVegMeal.getCost() << endl;
	}
}
