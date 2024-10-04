#pragma once
#include "util.h"

class Unit
{
protected:
	int health;
	int attack;
	bool dead;
	string name;
public:
	Unit(const string& name);
public:
	void setHealth(int helath);
	void setAttack(int attack);
	void setDead(bool dead);

	int getHealth();
	int getAttack();
	bool getDead();
	string getName();
	virtual void takeDamage(int damage);
	void ShowStat(int x, int y);
};

