#include "Fish.h"

GameManager& inst = GameManager::GetInstance();

Fish::Fish(const string& name) : Unit(name){}

void Fish::takeDamage(int damage)
{
	Unit::takeDamage(damage);
	cout << endl;
	cout << name << "��(��) " << damage << "��ŭ ���ظ� �Ծ����ϴ�.  ���� ü��: " << health << " " << endl;
	if (health <= 0)
	{
		cout << "����� �ٶ�!" << endl;
		cout << name << "�� ���Ҵ�!!" << endl;
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
