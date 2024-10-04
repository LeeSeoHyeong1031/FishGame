#include "Unit.h"

Unit::Unit(const string& name) : dead(false), name(name), health(0), attack(0){}

void Unit::setHealth(int health) { this->health = health;}

void Unit::setAttack(int attack) { this->attack = attack;}

void Unit::setDead(bool dead) { this->dead = dead; }

int Unit::getHealth() {return health;}

int Unit::getAttack() {return attack;}

bool Unit::getDead() { return dead; }

string Unit::getName()
{
	return name;
}

void Unit::takeDamage(int damage)
{
	health -= damage;
	if (health <= 0)
	{
		health = 0;
		dead = true;
	}
}

void Unit::ShowStat(int x, int y)
{
	gotoxy(x, y);
	cout << "이름 : " << name;
	gotoxy(x, y+1);
	cout << "체력 : " << health;
	gotoxy(x, y+2);
	cout << "공격력 : " << attack;
}
