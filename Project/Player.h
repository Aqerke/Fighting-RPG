#pragma once
class Player : public Character
{
public:
	Player(int health, int shield, int damage, int evasionChance)
	{
		this->health_ = health;
		this->shield_ = shield;
		this->damage_ = damage;
		this->evasionChance_ = evasionChance;
	}

	bool attack(Character& enemy, int playerAction, int enemyAction);

	int getExperience();
	void addExperience(int experience);

	friend class Shop;

private:
	int experience_ = 0;
};

