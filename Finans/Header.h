#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

using namespace std;

class Bank
{
public:
	Bank() {}
	virtual int GetBal() = 0;
	virtual void PutMoney() = 0;
	virtual void AddCost() = 0;
	virtual bool IsPin() = 0;
	virtual void Read() = 0;
	virtual void Clear() = 0;
	virtual void TopMonth(int mon) = 0;
	virtual void TopWeek(int mon, int day) = 0;
	virtual void TopCatMonth(int mon) = 0;
	virtual void TopCatWeek(int mon, int day) = 0;
	virtual void CostsDay(int mon, int day) = 0;
	virtual void CostsWeek(int mon, int day) = 0;
	virtual void CostsMonth(int mon) = 0;
	~Bank() = default;

private:

};

class Credit : public Bank
{
private:
	int balance;
	int pin = 1337;
	vector<string> categories = { "Продукты","Цветы","Развлечения","Электроника","Книги","Рестораны" };
	vector <string> files = { "Credit_Product.txt","Credit_Flowers.txt","Credit_Entertainment.txt","Credit_Electronic.txt","Credit_Books.txt","Credit_Restaurants.txt" };
	vector<int> buffer = { 0,0,0,0,0,0 };
	vector<int> buffer1;
	vector<int> buffer2;
	vector<int> buffer3;
	vector<int> buffer4;
	vector<int> buffer5;
	vector<int> buffer6;
public:
	Credit();
	int GetBal();
	void PutMoney();
	void AddCost();
	bool IsPin();
	void Read();
	void Clear();
	void TopMonth(int mon);
	void TopWeek(int mon, int day);
	void TopCatMonth(int mon);
	void TopCatWeek(int mon, int day);
	void CostsDay(int mon, int day);
	void CostsWeek(int mon, int day);
	void CostsMonth(int mon);
	~Credit();
};

class Debit : public Bank
{
private:
	int balance;
	int pin = 1337;
	vector<string> categories = { "Продукты","Цветы","Развлечения","Электроника","Книги","Рестораны" };
	vector <string> files = { "Debit_Product.txt","Debit_Flowers.txt","Debit_Entertainment.txt","Debit_Electronic.txt","Debit_Books.txt","Debit_Restaurants.txt" };
	vector<int> buffer = { 0,0,0,0,0,0 };
	vector<int> buffer1;
	vector<int> buffer2;
	vector<int> buffer3;
	vector<int> buffer4;
	vector<int> buffer5;
	vector<int> buffer6;
public:
	Debit();
	int GetBal();
	void PutMoney();
	void AddCost();
	bool IsPin();
	void Read();
	void Clear();
	void TopMonth(int mon);
	void TopWeek(int mon, int day);
	void TopCatMonth(int mon);
	void TopCatWeek(int mon, int day);
	void CostsDay(int mon, int day);
	void CostsWeek(int mon, int day);
	void CostsMonth(int mon);
	~Debit();
};
