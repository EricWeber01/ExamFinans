#include "Header.h"

int main() 
{
	int choose = 1, ind;
	Debit d;
	Credit c;
	Bank* ptr[2] = { &d,&c };
	do 
	{
		cout << "Дебитовая карта ==> 1" << "\n";
		cout << "Кредитовая карта ==> 2" << "\n";
		cout << "Выход ==> 3" << "\n";
		cin >> ind;
		ind--;
		do {
			int mon, day;
			cout << "Текущий баланс ==> 1" << "\n";
			cout << "Добавить расход по карте ==> 2" << "\n";
			cout << "Топ-3 расходов за месяц ==> 3" << "\n";
			cout << "Топ-3 расходов за неделю ==> 4" << "\n";
			cout << "Топ-3 категорий за месяц ==> 5" << "\n";
			cout << "Топ-3 категорий за неделю ==> 6" << "\n";
			cout << "Все расходы за день ==> 7" << "\n";
			cout << "Все расходы за неделю ==> 8" << "\n";
			cout << "Все расходы за месяц ==> 9" << "\n";
			cout << "Положить деньги на счет ==> 10" << "\n";
			cout << "В меню выбора карт ==> 11" << "\n";
			cout << "Введите номер ==> ";
			cin >> choose;
			system("cls");
			switch (choose) 
			{
			case (1):
			{
				cout << "Баланс ==> " << ptr[ind]->GetBal() << "UAH" << "\n";
				break;
			}
			case (2):
			{
				ptr[ind]->AddCost();
				break;
			}
			case (3):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				ptr[ind]->TopMonth(mon);
				break;
			}
			case (4):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				cout << "Введите день c начала недели ==> ";
				cin >> day;
				ptr[ind]->TopWeek(mon, day);
				break;
			}
			case (5):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				ptr[ind]->TopCatMonth(mon);
				break;
			}
			case (6):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				cout << "Введите день с начала недели ==> ";
				cin >> day;
				ptr[ind]->TopCatWeek(mon, day);
				break;
			}
			case (7):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				cout << "Введите день ==> ";
				cin >> day;
				ptr[ind]->CostsDay(mon, day);
				break;
			}
			case (8):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				cout << "Введите день c начала недели ==> ";
				cin >> day;
				ptr[ind]->CostsWeek(mon, day);
				break;
			}
			case (9):
			{
				cout << "Введите месяц ==> ";
				cin >> mon;
				ptr[ind]->CostsMonth(mon);
				break;
			}
			case (10):
			{
				ptr[ind]->PutMoney();
				break;
			}
			default:
				system("cls");
				break;
			}

		} while (choose != 0);
	} while (ind != 2);
}