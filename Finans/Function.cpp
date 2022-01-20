#include "Header.h"
Credit::Credit()
{
	ifstream fin("Credit_Balance.txt");
	string buffer;
	getline(fin, buffer);
	balance = stoi(buffer);
	fin.close();
}
int Credit::GetBal()
{
	return balance;
}
void Credit::PutMoney()
{
	int mon;
	if (this->IsPin() == true)
	{
		cout << "Введите сумму ==> ";
		cin >> mon;
		if (mon <= 0)
			cout << "Системная ошибка" << "\n";
		else
			balance += mon;
		cout << "Новый баланс ==> " << this->GetBal() << "UAH";
	}
}
void Credit::AddCost()
{
	int d, m, ch, mon;
	cout << "Новый Расход";
	cout << "Введите сумму ==> ";
	cin >> mon;
	cout << "Введите день ==> ";
	cin >> d;
	cout << "Введите месяц ==> ";
	cin >> m;
	cout << "Выберите категорию" << "\n";
	cout << "Продукты ==> 1" << "\n";
	cout << "Цветы ==> 2" << "\n";
	cout << "Развлечения ==> 3" << "\n";
	cout << "Электроника ==> 4" << "\n";
	cout << "Книги ==> 5" << "\n";
	cout << "Рестораны ==> 6" << "\n";
	cout << "Введите номер категории ==> ";
	cin >> ch;
	ofstream fout(files[ch - 1]);
	fout << m << endl;
	fout << d << endl;
	fout << mon << endl;
	balance -= mon;
	fout.close();
}
bool Credit::IsPin() 
{
	cout << "Введите PIN-код ==> ";
	int buffer;
	cin >> buffer;
	if (buffer == pin)
		return true;
	else 
	{
		cout << "Неверный PIN-код" << "\n";
		return false;
	}
}
void Credit::Read() 
{
	string str;
	ifstream fin(files[0]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer1.push_back(stoi(str));
	fin.close();
	fin.open(files[1]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer2.push_back(stoi(str));
	fin.close();
	fin.open(files[2]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer3.push_back(stoi(str));
	fin.close();
	fin.open(files[3]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer4.push_back(stoi(str));
	fin.close();
	fin.open(files[4]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer5.push_back(stoi(str));
	fin.close();
	fin.open(files[5]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer6.push_back(stoi(str));
	fin.close();
}
void Credit::Clear() 
{
	buffer.clear();
	buffer1.clear();
	buffer2.clear();
	buffer3.clear();
	buffer4.clear();
	buffer5.clear();
	buffer6.clear();
}
void Credit::TopMonth(int mon)
{
	this->Read();
	int max = 0;
	int cat = 0;
	int index;
	ofstream fout("Credit_Rating.txt", ios::app);
	cout << "Топ 3 затрат за месяц" << "\n";
	fout << "Топ 3 затрат за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		max = 0;
		for (size_t i = 0; i < buffer1.size(); i += 3)
		{
			if (buffer1[i + 2] > max && buffer1[i] == mon)
			{
				max = buffer1[i + 2];
				cat = 0;
				index = i;
			}
			for (size_t i = 0; i < buffer2.size(); i += 3)
			{
				if (buffer2[i + 2] > max && buffer2[i] == mon)
				{
					max = buffer2[i + 2];
					cat = 1;
					index = i;
				}
			}
			for (size_t i = 0; i < buffer3.size(); i += 3)
			{
				if (buffer3[i + 2] > max && buffer3[i] == mon)
				{
					max = buffer3[i + 2];
					cat = 2;
					index = i;
				}
			}
			for (size_t i = 0; i < buffer4.size(); i += 3)
			{
				if (buffer4[i + 2] > max && buffer4[i] == mon)
				{
					max = buffer4[i + 2];
					cat = 3;
					index = i;
				}
			}
			for (size_t i = 0; i < buffer5.size(); i += 3)
			{
				if (buffer5[i + 2] > max && buffer5[i] == mon)
				{
					max = buffer5[i + 2];
					cat = 4;
					index = i;
				}
			}
			for (size_t i = 0; i < buffer6.size(); i += 3)
			{
				if (buffer6[i + 2] > max && buffer6[i] == mon)
				{
					max = buffer6[i + 2];
					cat = 5;
					index = i;
				}
			}
			cout << categories[cat] << " ==> " << max << "UAH";
			fout << categories[cat] << " ==> " << max << "UAH";
			if (cat == 0 && buffer1.empty() == false)
			{
				buffer1.erase(buffer1.begin() + index, buffer1.begin() + index + 3);
			}
			else if (cat == 1 && buffer2.empty() == false)
			{
				buffer2.erase(buffer2.begin() + index, buffer2.begin() + index + 3);
			}
			else if (cat == 2 && buffer3.empty() == false)
			{
				buffer3.erase(buffer3.begin() + index, buffer3.begin() + index + 3);
			}
			else if (cat == 3 && buffer4.empty() == false)
			{
				buffer4.erase(buffer4.begin() + index, buffer4.begin() + index + 3);
			}
			else if (cat == 4 && buffer5.empty() == false)
			{
				buffer5.erase(buffer5.begin() + index, buffer5.begin() + index + 3);
			}
			else if (cat == 5 && buffer6.empty() == false)
			{
				buffer6.erase(buffer6.begin() + index, buffer6.begin() + index + 3);
			}
		}
		fout.close();
		this->Clear();
	}
}
void Credit::TopWeek(int mon, int day) 
{
	this->Read();
	int max;
	int cat;
	int index;
	ofstream fout("Credit_Rating.txt", ios::app);
	cout << "Топ 3 затраты за неделю" << "\n";
	fout << "Топ 3 затраты за неделю" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		max = 0;
		for (size_t i = 0; i < buffer1.size(); i += 3)
		{
			if (buffer1[i + 2] > max && buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7)
			{
				max = buffer1[i + 2];
				cat = 0;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer2.size(); i += 3)
		{
			if (buffer2[i + 2] > max && buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7)
			{
				max = buffer2[i + 2];
				cat = 1;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer3.size(); i += 3)
		{
			if (buffer3[i + 2] > max && buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7) 
			{
				max = buffer3[i + 2];
				cat = 2;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer4.size(); i += 3)
		{
			if (buffer4[i + 2] > max && buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7) 
			{
				max = buffer4[i + 2];
				cat = 3;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer5.size(); i += 3)
		{
			if (buffer5[i + 2] > max && buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7)
			{
				max = buffer5[i + 2];
				cat = 4;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer6.size(); i += 3)
		{
			if (buffer6[i + 2] > max && buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7) 
			{
				max = buffer6[i + 2];
				cat = 5;
				index = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		if (cat == 0 && buffer1.empty() == false) 
		{
			buffer1.erase(buffer1.begin() + index, buffer1.begin() + index + 3);
		}
		else if (cat == 1 && buffer2.empty() == false) 
		{
			buffer2.erase(buffer2.begin() + index, buffer2.begin() + index + 3);
		}
		else if (cat == 2 && buffer3.empty() == false)
		{
			buffer3.erase(buffer3.begin() + index, buffer3.begin() + index + 3);
		}
		else if (cat == 3 && buffer4.empty() == false)
		{
			buffer4.erase(buffer4.begin() + index, buffer4.begin() + index + 3);
		}
		else if (cat == 4 && buffer5.empty() == false) 
		{
			buffer5.erase(buffer5.begin() + index, buffer5.begin() + index + 3);
		}
		else if (cat == 5 && buffer6.empty() == false) 
		{
			buffer6.erase(buffer6.begin() + index, buffer6.begin() + index + 3);
		}
	}
	fout.close();
	this->Clear();
}
void Credit::TopCatMonth(int mon) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	int cat = 0;
	int max = 0;
	cout << "Топ 3 категорий за месяц" << "\n";
	ofstream fout("Credit_Rating.txt", ios::app);
	fout << "\nТоп 3 категорий за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] > max) 
			{
				max = buffer[i];
				cat = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		buffer[cat] = 0;
		max = 0;
	}
	fout.close();
	this->Clear();
}
void Credit::TopCatWeek(int mon, int day) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7)
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	int cat = 0;
	int max = 0;
	cout << "Топ 3 категорий за месяц" << "\n";
	ofstream fout("Credit_Rating.txt", ios::app);
	fout << "Топ 3 категорий за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] > max)
			{
				max = buffer[i];
				cat = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		buffer[cat] = 0;
		max = 0;
	}
	fout.close();
	this->Clear();
}
void Credit::CostsDay(int mon, int day)
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1])
		{
			buffer[0] += buffer1[i + 2];
		}
	}

	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1]) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1])
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1]) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1]) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1]) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	cout << "Затраты за день" << "\n";
	ofstream fout("Credit_Rating.txt", ios::app);
	fout << "Затраты за день" << "\n";
	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
		fout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
	}
	fout.close();
	this->Clear();
}
void Credit::CostsWeek(int mon, int day) {
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	ofstream fout("Credit_Rating.txt", ios::app);
	cout << "Затраты за неделю" << "\n";
	fout << "Затраты за неделю" << "\n";
	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
		fout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
	}
	fout.close();
	this->Clear();
}
void Credit::CostsMonth(int mon)
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon)
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	cout << "Затраты за месяц" << "\n";
	ofstream fout("Credit_Rating.txt", ios::app);
	fout << "Затраты за месяц" << "\n";
	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
		fout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
	}
	fout.close();
	this->Clear();
}
Credit::~Credit() 
{
	ofstream fout("Credit_Balance.txt");
	fout << to_string(balance);
	fout.close();
}

Debit::Debit() 
{
	ifstream fin("Debit_Balance.txt");
	string buffer;
	getline(fin, buffer);
	balance = stoi(buffer);
	fin.close();
}
int Debit::GetBal()
{ 
	return balance; 
}
void Debit::PutMoney() 
{
	int mon;
	if (this->IsPin() == true) 
	{
		cout << "Введите сумму ==> ";
		cin >> mon;
		if (mon <= 0)
			cout << "Системная ошибка" << "\n";
		else
			balance += mon;
		cout << "Новый баланс ==> " << this->GetBal() << "UAH";
	}
}
void Debit::AddCost() 
{
	int d, m, ch, mon;
	cout << "Новый Расход" << "\n";
	cout << "Введите сумму ==> ";
	cin >> mon;
	if (mon > this->balance) 
	{
		cout << "Недостаточно средств" << "\n";
	}
	else 
	{
		cout << "Введите день ==> ";
		cin >> d;
		cout << "Введите месяц ==> ";
		cin >> m;
		cout << "Выберите категорию" <<"\n";
		cout << "Продукты ==> 1" << "\n";
		cout << "Цветы ==> 2" << "\n";
		cout << "Развлечения ==> 3" << "\n";
		cout << "Электроника ==> 4" << "\n";
		cout << "Книги ==> 5" << "\n";
		cout << "Рестораны ==> 6" << "\n";
		cout << "Введите номер категории ==> ";
		cin >> ch;
		ofstream fout(files[ch - 1]);
		fout << m << endl;
		fout << d << endl;
		fout << mon << endl;
		balance -= mon;
		fout.close();
	}
}
bool Debit::IsPin() 
{
	int buffer;
	cout << "Введите PIN-код ==> ";
	cin >> buffer;
	if (buffer == pin)
		return true;
	else 
	{
		cout << "Неверный PIN-код";
		return false;
	}
}
void Debit::Read() 
{
	string str;
	ifstream fin(files[0]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer1.push_back(stoi(str));
	fin.close();
	fin.open(files[1]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer2.push_back(stoi(str));
	fin.close();
	fin.open(files[2]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer3.push_back(stoi(str));
	fin.close();
	fin.open(files[3]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer4.push_back(stoi(str));
	fin.close();
	fin.open(files[4]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer5.push_back(stoi(str));
	fin.close();
	fin.open(files[5]);
	while (getline(fin, str))
		if (str.size() != 0)
			buffer6.push_back(stoi(str));
	fin.close();
}
void Debit::Clear() 
{
	buffer.clear();
	buffer1.clear();
	buffer2.clear();
	buffer3.clear();
	buffer4.clear();
	buffer5.clear();
	buffer6.clear();
}
void Debit::TopMonth(int mon) 
{
	this->Read();
	int max = 0;
	int cat = 0;
	int index;
	ofstream fout("Debit_Rating.txt", ios::app);
	cout << "Топ 3 затрат за месяц" << "\n";
	fout << "Топ 3 затрат за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		max = 0;
		for (size_t i = 0; i < buffer1.size(); i += 3)
		{
			if (buffer1[i + 2] > max && buffer1[i] == mon) 
			{
				max = buffer1[i + 2];
				cat = 0;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer2.size(); i += 3)
		{
			if (buffer2[i + 2] > max && buffer2[i] == mon) 
			{
				max = buffer2[i + 2];
				cat = 1;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer3.size(); i += 3)
		{
			if (buffer3[i + 2] > max && buffer3[i] == mon) 
			{
				max = buffer3[i + 2];
				cat = 2;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer4.size(); i += 3)
		{
			if (buffer4[i + 2] > max && buffer4[i] == mon) 
			{
				max = buffer4[i + 2];
				cat = 3;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer5.size(); i += 3)
		{
			if (buffer5[i + 2] > max && buffer5[i] == mon) 
			{
				max = buffer5[i + 2];
				cat = 4;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer6.size(); i += 3)
		{
			if (buffer6[i + 2] > max && buffer6[i] == mon) 
			{
				max = buffer6[i + 2];
				cat = 5;
				index = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		if (cat == 0) 
		{
			buffer1.erase(buffer1.begin() + index, buffer1.begin() + index + 3);
		}
		else if (cat == 1) 
		{
			buffer2.erase(buffer2.begin() + index, buffer2.begin() + index + 3);
		}
		else if (cat == 2) 
		{
			buffer3.erase(buffer3.begin() + index, buffer3.begin() + index + 3);
		}
		else if (cat == 3) 
		{
			buffer4.erase(buffer4.begin() + index, buffer4.begin() + index + 3);
		}
		else if (cat == 4)
		{
			buffer5.erase(buffer5.begin() + index, buffer5.begin() + index + 3);
		}
		else if (cat == 5) 
		{
			buffer6.erase(buffer6.begin() + index, buffer6.begin() + index + 3);
		}
	}
	fout.close();
	this->Clear();
}
void Debit::TopWeek(int mon, int day) 
{
	this->Read();
	int max;
	int cat;
	int index;
	ofstream fout("Debit_Rating.txt", ios::app);
	cout << "Тoп3 затрат за неделю" << "\n";
	fout << "Топ-3 затрат за неделю" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		max = 0;
		for (size_t i = 0; i < buffer1.size(); i += 3)
		{
			if (buffer1[i + 2] > max && buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7)
			{
				max = buffer1[i + 2];
				cat = 0;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer2.size(); i += 3)
		{
			if (buffer2[i + 2] > max && buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7) 
			{
				max = buffer2[i + 2];
				cat = 1;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer3.size(); i += 3)
		{
			if (buffer3[i + 2] > max && buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7) 
			{
				max = buffer3[i + 2];
				cat = 2;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer4.size(); i += 3)
		{
			if (buffer4[i + 2] > max && buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7) 
			{
				max = buffer4[i + 2];
				cat = 3;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer5.size(); i += 3)
		{
			if (buffer5[i + 2] > max && buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7) 
			{
				max = buffer5[i + 2];
				cat = 4;
				index = i;
			}
		}
		for (size_t i = 0; i < buffer6.size(); i += 3)
		{
			if (buffer6[i + 2] > max && buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7) 
			{
				max = buffer6[i + 2];
				cat = 5;
				index = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		if (cat == 0) 
		{
			buffer1.erase(buffer1.begin() + index, buffer1.begin() + index + 3);
		}
		else if (cat == 1) 
		{
			buffer2.erase(buffer2.begin() + index, buffer2.begin() + index + 3);
		}
		else if (cat == 2) 
		{
			buffer3.erase(buffer3.begin() + index, buffer3.begin() + index + 3);
		}
		else if (cat == 3) 
		{
			buffer4.erase(buffer4.begin() + index, buffer4.begin() + index + 3);
		}
		else if (cat == 4) 
		{
			buffer5.erase(buffer5.begin() + index, buffer5.begin() + index + 3);
		}
		else if (cat == 5) 
		{
			buffer6.erase(buffer6.begin() + index, buffer6.begin() + index + 3);
		}
	}
	fout.close();
	this->Clear();
}
void Debit::TopCatMonth(int mon)
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	int cat = 0;
	int max = 0;
	cout << "Топ 3 категорий за месяц" << "\n";
	ofstream fout("drating.txt", ios::app);
	fout << "Топ3 категорий за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] > max) 
			{
				max = buffer[i];
				cat = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH" << "\n";
		fout << categories[cat] << " ==> " << max << "UAH" << "\n";
		buffer[cat] = 0;
		max = 0;
	}
	fout.close();
	this->Clear();
}
void Debit::TopCatWeek(int mon, int day) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	int cat = 0;
	int max = 0;
	cout << "Топ3 категорий за месяц" << "\n";
	ofstream fout("Debit_Rating.txt", ios::app);
	fout << "Топ 3 категорий за месяц" << "\n";
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t i = 0; i < buffer.size(); i++)
		{
			if (buffer[i] > max) 
			{
				max = buffer[i];
				cat = i;
			}
		}
		cout << categories[cat] << " ==> " << max << "UAH";
		fout << categories[cat] << " ==> " << max << "UAH";
		buffer[cat] = 0;
		max = 0;
	}
	fout.close();
	this->Clear();
}
void Debit::CostsDay(int mon, int day) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1]) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1]) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1]) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1]) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1]) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1]) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	cout << "Затраты за день" << "\n";
	ofstream fout("Debit_Rating.txt", ios::app);
	fout << "Затраты за день" << "\n";
	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
		fout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
	}
	fout.close();
	this->Clear();
}
void Debit::CostsWeek(int mon, int day) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon && day >= buffer1[i + 1] && day <= buffer1[i + 1] + 7) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon && day >= buffer2[i + 1] && day <= buffer2[i + 1] + 7) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon && day >= buffer3[i + 1] && day <= buffer3[i + 1] + 7)
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon && day >= buffer4[i + 1] && day <= buffer4[i + 1] + 7)
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon && day >= buffer5[i + 1] && day <= buffer5[i + 1] + 7) 
		{
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon && day >= buffer6[i + 1] && day <= buffer6[i + 1] + 7)
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	ofstream fout("Debit_Rating.txt", ios::app);
	cout << "Затраты за неделю" << "\n";
	fout << "Затраты за неделю" << "\n";

	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
		fout << categories[i] << " ==> " << buffer[i] << "UAH" << "\n";
	}
	fout.close();
	this->Clear();
}
void Debit::CostsMonth(int mon) 
{
	this->Read();
	for (size_t i = 0; i < buffer1.size(); i += 3)
	{
		if (buffer1[i] == mon) 
		{
			buffer[0] += buffer1[i + 2];
		}
	}
	for (size_t i = 0; i < buffer2.size(); i += 3)
	{
		if (buffer2[i] == mon) 
		{
			buffer[1] += buffer2[i + 2];
		}
	}
	for (size_t i = 0; i < buffer3.size(); i += 3)
	{
		if (buffer3[i] == mon) 
		{
			buffer[2] += buffer3[i + 2];
		}
	}
	for (size_t i = 0; i < buffer4.size(); i += 3)
	{
		if (buffer4[i] == mon) 
		{
			buffer[3] += buffer4[i + 2];
		}
	}
	for (size_t i = 0; i < buffer5.size(); i += 3)
	{
		if (buffer5[i] == mon) {
			buffer[4] += buffer5[i + 2];
		}
	}
	for (size_t i = 0; i < buffer6.size(); i += 3)
	{
		if (buffer6[i] == mon) 
		{
			buffer[5] += buffer6[i + 2];
		}
	}
	cout << "Затраты за месяц" << "\n";
	ofstream fout("Debit_Rrating.txt", ios::app);
	fout << "Затраты за месяц" << "\n";
	for (size_t i = 0; i < buffer.size(); i++)
	{
		cout << categories[i] << " ==> " << buffer[i] << "UAH";
		fout << categories[i] << " ==> " << buffer[i] << "UAH";
	}
	fout.close();
	this->Clear();
}
Debit::~Debit() 
{
	ofstream fout("Debit_Balance.txt");
	fout << to_string(balance);
	fout.close();
}