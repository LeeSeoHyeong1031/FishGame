#include "Fish.h"

GameManager& inst = GameManager::GetInstance();

Fish::Fish(const string& name) : Unit(name){}

void Fish::takeDamage(int damage)
{
	Unit::takeDamage(damage);
	cout << endl;
	cout << name << "이(가) " << damage << "만큼 피해를 입었습니다.  남은 체력: " << health << " " << endl;
	if (health <= 0)
	{
		cout << "물고기 겟또!" << endl;
		cout << name << "를 낚았다!!" << endl;
		inst.addExp(exp);
	}
}

void Fish::SetUP(int level, int health, int damage, int exp, int money)
{
	this->level = level;
	this->health = health;
	this->attack = damage;
	this->exp = exp;
	this->money = money;
}
