#include "includes.h"

void shop(Player& player);

int main()
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(static_cast<unsigned int>(time(0)));

    Player player(100, 25, 25, 25);

    cout << "Добро пожаловать в подземелье!" << endl;
    cout << "Ваши характеристики: " << player.getStats() << endl;

    while (player.isAlive())
    {
        Enemy enemy(25, 150, 10, 50, 10, 50, 1, 10);
        Battle battle(player, enemy);
        battle.start();

		shop(player);
    }

	cout << "Игра окончена!" << endl;
	cout << "ВАши характеристики: " << player.getStats() << endl;
	system("pause");
}

void shop(Player& player)
{
	cout << "\n\n || Магазин ||" << endl;
	cout << "Вы можете выполнить только одну покупку перед боем" << endl;
	cout << "1. +25 здоровья = 1 очко опыта" << endl;
	cout << "2. +5 к защите от щита = 2 очко опыта" << endl;
	cout << "3. +10 к атаке = 2 очко опыта" << endl;
	cout << "4. +1% к шансу уклонения от атаки = 3 очка опыта" << endl;
	cout << "5. Выход из магазина" << endl << endl;
	cout << "Ваш опыт: " << player.getExperience() << endl;
	cout << "Ваш выбор: ";

	int userInput = 0;
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		player.addHealth(25);
		if (player.getExperience() - 1 >= 0)
		{
			player.addExperience(-1);
		}
		else
		{
			cout << "У Вас недостаточно опыта!" << endl;
		}

		cout << endl << "Вы купили +25 к здоровью за 1 очко опыта" << endl;

		break;
	case 2:
		player.addShield(5);
		if (player.getExperience() - 2 >= 0)
		{
			player.addExperience(-2);
		}
		else
		{
			cout << "У Вас недостаточно опыта!" << endl;
		}

		cout << endl << "Вы купили +5 к щиту за 2 очка опыта" << endl;

		break;
	case 3:
		player.addDamage(25);
		if (player.getExperience() - 2 >= 0)
		{
			player.addExperience(-2);
		}
		else
		{
			cout << "У Вас недостаточно опыта!" << endl;
		}

		cout << endl << "Вы купили +25 к атаке за 2 очка опыта" << endl;

		break;
	case 4:
		player.addEvasionChance(1);
		if (player.getExperience() - 3 >= 0)
		{
			player.addExperience(-3);
		}
		else
		{
			cout << "У Вас недостаточно опыта!" << endl;
		}

		cout << endl << "Вы купили +1% к шансу уклонения за 3 очка опыта" << endl;

		break;
	case 5:
		break;
	}
}