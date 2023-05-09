#include "includes.h"

void Battle::start()
{
	cout << endl << "Вы встретили противника!" << endl << "Характеристики: " << enemy_->getStats() << endl;

	// Пока игрок или противник не умрут - продолжаем битву
	while (player_->isAlive() && enemy_->isAlive())
	{
		// Если пользователь сбежал из битвы - заканчиваем битву, соответственно
		if (getUserAction() == false)
			break;

		cout << endl << "Противник: " << enemy_->getStats() << endl;
		cout << "Игрок: " << player_->getStats() << endl << endl;
	}

	cout << "Вы победили противника. +3 очка опыта";
	player_->addExperience(3);
}

bool Battle::getUserAction()
{
	cout << "Выберите действие:" << endl;
	cout << "1. Атаковать" << endl;
	cout << "2. Закрыться щитом" << endl;
	cout << "3. Пнуть(25 % от урона, игнорирование щита)" << endl;
	cout << "4. Сбежать(получить 50 % урона от атаки противника, " <<
		"и закончить бой.Отнимается 2 очка опыта)" << endl << endl;
	cout << "Ваш выбор: ";
	
	int userInput = 0;
	cin >> userInput;

	int enemyAction = rand() % 3 + 1;

	cout << endl << "Вы выбрали: " << actions[userInput - 1] << endl;
	cout << "Противник выбрал: " << actions[enemyAction - 1] << endl;

	return player_->attack(*enemy_, userInput, enemyAction);
}