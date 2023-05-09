#include "includes.h"

void Character::getAttackDamage(int damage)
{
	health_ -= damage;
}

int Character::getHealth()
{
	return health_;
}

int Character::getShield()
{
	return shield_;
}

int Character::getDamage()
{
	return damage_;
}

int Character::getEvasionChance()
{
	return evasionChance_;
}

void Character::addHealth(int health)
{
	this->health_ += health;
}

void Character::addShield(int shield)
{
	this->shield_ += shield;
}

void Character::addDamage(int damage)
{
	this->damage_ += damage;
}

void Character::addEvasionChance(int evasionChance)
{
	this->evasionChance_ += evasionChance;
}

string Character::getStats()
{
	return to_string(health_) + " ��������, " + to_string(shield_) + " ����, " + to_string(damage_) + " �����, " + to_string(evasionChance_) + "% ���� ���������";
}

bool Character::isAlive()
{
	return health_ > 0;
}