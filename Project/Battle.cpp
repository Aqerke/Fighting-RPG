#include "includes.h"

void Battle::start()
{
	cout << endl << "�� ��������� ����������!" << endl << "��������������: " << enemy_->getStats() << endl;

	// ���� ����� ��� ��������� �� ����� - ���������� �����
	while (player_->isAlive() && enemy_->isAlive())
	{
		// ���� ������������ ������ �� ����� - ����������� �����, ��������������
		if (getUserAction() == false)
			break;

		cout << endl << "���������: " << enemy_->getStats() << endl;
		cout << "�����: " << player_->getStats() << endl << endl;
	}

	cout << "�� �������� ����������. +3 ���� �����";
	player_->addExperience(3);
}

bool Battle::getUserAction()
{
	cout << "�������� ��������:" << endl;
	cout << "1. ���������" << endl;
	cout << "2. ��������� �����" << endl;
	cout << "3. �����(25 % �� �����, ������������� ����)" << endl;
	cout << "4. �������(�������� 50 % ����� �� ����� ����������, " <<
		"� ��������� ���.���������� 2 ���� �����)" << endl << endl;
	cout << "��� �����: ";
	
	int userInput = 0;
	cin >> userInput;

	int enemyAction = rand() % 3 + 1;

	cout << endl << "�� �������: " << actions[userInput - 1] << endl;
	cout << "��������� ������: " << actions[enemyAction - 1] << endl;

	return player_->attack(*enemy_, userInput, enemyAction);
}