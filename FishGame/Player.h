#pragma once
#include"Unit.h"
class Player : public Unit
{
private:
	int patience; //�γ���
	int maxHealth; //�÷��̾� �ִ� ü��
public:
	Player(const string& name);
	void takeDamage(int damage)override;
	void setPatience(int patience);
	void setMaxHealth(int health);
	int getPatience();
	int getMaxHealth();
	void Init();
};

