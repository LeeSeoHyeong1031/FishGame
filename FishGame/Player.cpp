#include "Player.h"

Player::Player(const string& name) : Unit(name)
{
	this->health = 70;
	this->attack = 1;
	this->patience = 0;
	this->maxHealth = health;
}

void Player::takeDamage(int damage)
{
	Unit::takeDamage(damage);
}

void Player::setPatience(int patience) {this->patience = patience;}

void Player::setMaxHealth(int health)
{
	this->maxHealth = health;
}

int Player::getPatience() {return patience;}

int Player::getMaxHealth()
{
	return maxHealth;
}

void Player::Init()
{
	this->health = 70;
	this->attack = 1;
	this->patience = 0;
	this->maxHealth = health;
	this->dead = false;
}
