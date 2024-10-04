#include "Item.h"

Item::Item(const string& name, const int price, const int health, const int damage, const int patience) :name(name), price(price), health(health), damage(damage), patience(patience){}

void Item::setPrice(int price)
{
	this->price = price;
}

string Item::getName()
{
	return name;
}

int Item::getPrice()
{
	return price;
}

int Item::getHealth()
{
	return health;
}

int Item::getDamage()
{
	return damage;
}

int Item::getPatience()
{
	return patience;
}

void Item::setCount()
{
	count = 0;
}

int Item::getCount()
{
	return count;
}
