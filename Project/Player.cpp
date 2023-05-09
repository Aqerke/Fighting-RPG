#include "includes.h"

bool Player::attack(Character& enemy, int playerAction, int enemyAction)
{
	int random = rand() % 100 + 1;

	if (playerAction == ATTACKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// Если мы не промазали
			if (random > enemy.getEvasionChance())
			{
				cout << endl << "Вы нанесли противнику " << damage_ << " урона" << endl;
				enemy.getAttackDamage(damage_);

				// Если противник не промазал
				if (random > evasionChance_)
				{
					getAttackDamage(enemy.getDamage());
					cout << "Противник нанёс Вам " << enemy.getDamage() << " урона" << endl;
				}
				else // Если противник промазал
				{
					cout << "Противник промахнулся" << endl;
				}

				experience_++;
				cout << "Ваши очки опыта: " << experience_ << "(+1)" << endl;
			}
			else // Если мы промазали
			{
				// Если противник не промазал
				if (random > evasionChance_)
				{
					getAttackDamage(enemy.getDamage());
					cout << "Противник нанёс Вам " << enemy.getDamage() << " урона" << endl;
				}
				else // Если противник промазал
				{
					cout << "Противник промахнулся" << endl;
				}

				cout << "Вы промахнулись" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			// Если мы не промазали
			if (random > enemy.getEvasionChance())
			{
				enemy.getAttackDamage(static_cast<int>(damage_ / 4));

				cout << endl << "Вы нанесли противнику " << static_cast<int>(damage_ / 4) << " урона" << endl;
				cout << "Противник нанёс Вам 0 урона" << endl;
				experience_++;
				cout << "Ваши очки опыта: " << experience_ << "(+1)" << endl;
			}
			else // Если мы промазали
			{
				cout << "Вы промахнулись" << endl;
				cout << "Противник нанёс Вам 0 урона" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		case KICKING:
			// Если мы не промазали
			if (random > enemy.getEvasionChance())
			{
				enemy.getAttackDamage(damage_);

				cout << endl << "Вы нанесли противнику " << damage_ << " урона" << endl;
				cout << "Противник нанёс Вам 0 урона" << endl;
				experience_ += 2;
				cout << "Ваши очки опыта: " << experience_ << "(+2)" << endl;
			}
			else // Если мы промазали
			{
				cout << "Вы промахнулись" << endl;
				cout << "Противник нанёс Вам 0 урона" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		}
	}

	if (playerAction == BLOCKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// Если противник не промазал
			if (random > evasionChance_)
			{
				getAttackDamage(enemy.getDamage() - shield_);

				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник нанёс Вам " << enemy.getDamage() - shield_ << " урона" << endl;
				experience_--;
				cout << "Ваши очки опыта: " << experience_ << "(-1)" << endl;
			}
			else // Если противник промазал
			{
				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник промахнулся" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			cout << endl << "Вы нанесли противнику 0 урона" << endl;
			cout << "Противник нанёс Вам 0 урона" << endl;
			cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;

			break;
		case KICKING:
			// Если мы не промазали
			if (random > enemy.getEvasionChance())
			{
				getAttackDamage(static_cast<int>(enemy.getDamage() / 4));

				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник нанёс Вам " << static_cast<int>(enemy.getDamage() / 4) << " урона" << endl;
				experience_--;
				cout << "Ваши очки опыта: " << experience_ << "(-1)" << endl;
			}
			else // Если мы промазали
			{
				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник промахнулся" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		}
	}

	if (playerAction == KICKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// Если противник не промазал
			if (random > evasionChance_)
			{
				getAttackDamage(enemy.getDamage());

				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник нанёс Вам " << enemy.getDamage() << " урона" << endl;
				experience_--;
				cout << "Ваши очки опыта: " << experience_ << "(-1)" << endl;
			}
			else // Если противник промазал
			{
				cout << endl << "Вы нанесли противнику 0 урона" << endl;
				cout << "Противник промахнулся" << endl;
				cout << "Ваши очки опыта: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			enemy.getAttackDamage(static_cast<int>(damage_ / 4));

			cout << endl << "Вы нанесли противнику " << static_cast<int>(damage_ / 4) << " урона" << endl;
			cout << "Противник нанёс Вам 0 урона" << endl;
			experience_ += 2;
			cout << "Ваши очки опыта: " << experience_ << "(+2)" << endl;

			break;
		case KICKING:
			getAttackDamage(static_cast<int>(enemy.getDamage() / 4));
			enemy.getAttackDamage(static_cast<int>(damage_ / 4));

			cout << endl << "Вы нанесли противнику " << static_cast<int>(damage_ / 4) << " урона" << endl;
			cout << "Противник нанёс Вам " << static_cast<int>(enemy.getDamage() / 4) << " урона" << endl;
			experience_++;
			cout << "Ваши очки опыта: " << experience_ << "(+1)" << endl;

			break;
		}
	}

	if (playerAction == RUNNING_AWAY)
	{
		getAttackDamage(enemy.getDamage() / 2);
		cout << endl << "Вы сбежали от битвы. Вы получили " << enemy.getDamage() / 2 << " урона." << endl;
		experience_ -= 2;
		cout << "Ваши очки опыта: " << experience_ << "(-2)" << endl;
		return false;
	}

	return true;
}

int Player::getExperience()
{
	return experience_;
}

void Player::addExperience(int experience)
{
	this->experience_ += experience;
}