#include "includes.h"

bool Player::attack(Character& enemy, int playerAction, int enemyAction)
{
	int random = rand() % 100 + 1;

	if (playerAction == ATTACKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// ���� �� �� ���������
			if (random > enemy.getEvasionChance())
			{
				cout << endl << "�� ������� ���������� " << damage_ << " �����" << endl;
				enemy.getAttackDamage(damage_);

				// ���� ��������� �� ��������
				if (random > evasionChance_)
				{
					getAttackDamage(enemy.getDamage());
					cout << "��������� ���� ��� " << enemy.getDamage() << " �����" << endl;
				}
				else // ���� ��������� ��������
				{
					cout << "��������� �����������" << endl;
				}

				experience_++;
				cout << "���� ���� �����: " << experience_ << "(+1)" << endl;
			}
			else // ���� �� ���������
			{
				// ���� ��������� �� ��������
				if (random > evasionChance_)
				{
					getAttackDamage(enemy.getDamage());
					cout << "��������� ���� ��� " << enemy.getDamage() << " �����" << endl;
				}
				else // ���� ��������� ��������
				{
					cout << "��������� �����������" << endl;
				}

				cout << "�� ������������" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			// ���� �� �� ���������
			if (random > enemy.getEvasionChance())
			{
				enemy.getAttackDamage(static_cast<int>(damage_ / 4));

				cout << endl << "�� ������� ���������� " << static_cast<int>(damage_ / 4) << " �����" << endl;
				cout << "��������� ���� ��� 0 �����" << endl;
				experience_++;
				cout << "���� ���� �����: " << experience_ << "(+1)" << endl;
			}
			else // ���� �� ���������
			{
				cout << "�� ������������" << endl;
				cout << "��������� ���� ��� 0 �����" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		case KICKING:
			// ���� �� �� ���������
			if (random > enemy.getEvasionChance())
			{
				enemy.getAttackDamage(damage_);

				cout << endl << "�� ������� ���������� " << damage_ << " �����" << endl;
				cout << "��������� ���� ��� 0 �����" << endl;
				experience_ += 2;
				cout << "���� ���� �����: " << experience_ << "(+2)" << endl;
			}
			else // ���� �� ���������
			{
				cout << "�� ������������" << endl;
				cout << "��������� ���� ��� 0 �����" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		}
	}

	if (playerAction == BLOCKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// ���� ��������� �� ��������
			if (random > evasionChance_)
			{
				getAttackDamage(enemy.getDamage() - shield_);

				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� ���� ��� " << enemy.getDamage() - shield_ << " �����" << endl;
				experience_--;
				cout << "���� ���� �����: " << experience_ << "(-1)" << endl;
			}
			else // ���� ��������� ��������
			{
				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� �����������" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			cout << endl << "�� ������� ���������� 0 �����" << endl;
			cout << "��������� ���� ��� 0 �����" << endl;
			cout << "���� ���� �����: " << experience_ << "(+0)" << endl;

			break;
		case KICKING:
			// ���� �� �� ���������
			if (random > enemy.getEvasionChance())
			{
				getAttackDamage(static_cast<int>(enemy.getDamage() / 4));

				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� ���� ��� " << static_cast<int>(enemy.getDamage() / 4) << " �����" << endl;
				experience_--;
				cout << "���� ���� �����: " << experience_ << "(-1)" << endl;
			}
			else // ���� �� ���������
			{
				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� �����������" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		}
	}

	if (playerAction == KICKING)
	{
		switch (enemyAction)
		{
		case ATTACKING:
			// ���� ��������� �� ��������
			if (random > evasionChance_)
			{
				getAttackDamage(enemy.getDamage());

				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� ���� ��� " << enemy.getDamage() << " �����" << endl;
				experience_--;
				cout << "���� ���� �����: " << experience_ << "(-1)" << endl;
			}
			else // ���� ��������� ��������
			{
				cout << endl << "�� ������� ���������� 0 �����" << endl;
				cout << "��������� �����������" << endl;
				cout << "���� ���� �����: " << experience_ << "(+0)" << endl;
			}

			break;
		case BLOCKING:
			enemy.getAttackDamage(static_cast<int>(damage_ / 4));

			cout << endl << "�� ������� ���������� " << static_cast<int>(damage_ / 4) << " �����" << endl;
			cout << "��������� ���� ��� 0 �����" << endl;
			experience_ += 2;
			cout << "���� ���� �����: " << experience_ << "(+2)" << endl;

			break;
		case KICKING:
			getAttackDamage(static_cast<int>(enemy.getDamage() / 4));
			enemy.getAttackDamage(static_cast<int>(damage_ / 4));

			cout << endl << "�� ������� ���������� " << static_cast<int>(damage_ / 4) << " �����" << endl;
			cout << "��������� ���� ��� " << static_cast<int>(enemy.getDamage() / 4) << " �����" << endl;
			experience_++;
			cout << "���� ���� �����: " << experience_ << "(+1)" << endl;

			break;
		}
	}

	if (playerAction == RUNNING_AWAY)
	{
		getAttackDamage(enemy.getDamage() / 2);
		cout << endl << "�� ������� �� �����. �� �������� " << enemy.getDamage() / 2 << " �����." << endl;
		experience_ -= 2;
		cout << "���� ���� �����: " << experience_ << "(-2)" << endl;
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