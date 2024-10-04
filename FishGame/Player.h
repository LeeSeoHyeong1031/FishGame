#pragma once
#include"Unit.h"
class Player : public Unit
{
private:
	int patience; //인내심
	int maxHealth; //플레이어 최대 체력
public:
	Player(const string& name);
	void takeDamage(int damage)override;
	void setPatience(int patience);
	void setMaxHealth(int health);
	int getPatience();
	int getMaxHealth();
	void Init();
};

