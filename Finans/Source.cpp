#include "Header.h"

int main() 
{
	int choose = 1, ind;
	Debit d;
	Credit c;
	Bank* ptr[2] = { &d,&c };
	do 
	{
		cout << "��������� ����� ==> 1" << "\n";
		cout << "���������� ����� ==> 2" << "\n";
		cout << "����� ==> 3" << "\n";
		cin >> ind;
		ind--;
		do {
			int mon, day;
			cout << "������� ������ ==> 1" << "\n";
			cout << "�������� ������ �� ����� ==> 2" << "\n";
			cout << "���-3 �������� �� ����� ==> 3" << "\n";
			cout << "���-3 �������� �� ������ ==> 4" << "\n";
			cout << "���-3 ��������� �� ����� ==> 5" << "\n";
			cout << "���-3 ��������� �� ������ ==> 6" << "\n";
			cout << "��� ������� �� ���� ==> 7" << "\n";
			cout << "��� ������� �� ������ ==> 8" << "\n";
			cout << "��� ������� �� ����� ==> 9" << "\n";
			cout << "�������� ������ �� ���� ==> 10" << "\n";
			cout << "� ���� ������ ���� ==> 11" << "\n";
			cout << "������� ����� ==> ";
			cin >> choose;
			system("cls");
			switch (choose) 
			{
			case (1):
			{
				cout << "������ ==> " << ptr[ind]->GetBal() << "UAH" << "\n";
				break;
			}
			case (2):
			{
				ptr[ind]->AddCost();
				break;
			}
			case (3):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				ptr[ind]->TopMonth(mon);
				break;
			}
			case (4):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				cout << "������� ���� c ������ ������ ==> ";
				cin >> day;
				ptr[ind]->TopWeek(mon, day);
				break;
			}
			case (5):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				ptr[ind]->TopCatMonth(mon);
				break;
			}
			case (6):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				cout << "������� ���� � ������ ������ ==> ";
				cin >> day;
				ptr[ind]->TopCatWeek(mon, day);
				break;
			}
			case (7):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				cout << "������� ���� ==> ";
				cin >> day;
				ptr[ind]->CostsDay(mon, day);
				break;
			}
			case (8):
			{
				cout << "������� ����� ==> ";
				cin >> mon;
				cout << "������� ���� c ������ ������ ==> ";
				cin >> day;
				ptr[ind]->CostsWeek(mon, day);
				break;
			}
			case (9):
			{
				cout << "������� ����� ==> ";
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