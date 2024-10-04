#pragma once
#include "util.h"
class Item
{
private:
	string name;
	int price;
	int health;
	int damage;
	int patience;
	int count = 1;
public:
	Item(const string& name, const int price, const int health, const int damage, const int patience);
	void setPrice(int price);
	string getName();
	int getPrice();
	int getHealth();
	int getDamage();
	int getPatience();
	void setCount();
	int getCount();
};

