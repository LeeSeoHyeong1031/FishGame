#pragma once
#include"Unit.h"
#include "GameManager.h"
class Fish : public Unit
{
public:
	int level;
	int exp;
	int money;
public:
	Fish(const string& name);
public:
	void takeDamage(int damage)override;
	void SetUP(int level, int health, int damage, int exp, int money);
};

