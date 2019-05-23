#include <iostream>
#include "account.h"
#include "date.h"

using namespace std;
double Account::total = 0;
void SavingsAccount::deposit(Date date, double amount)
{
	accumulate(date);
	balance += amount;
	total += amount;

}
void SavingsAccount::withdraw(Date date, double amount)
{
	accumulate(date);
	balance -= amount;
	total -= amount;
}
double SavingsAccount::accumulate(Date date)
{
	int d = lastDate.distance(date);
	for (int i = 0; i <d; i++)
	{
		accumulation += balance;
	}
	lastDate = date;
	return 0;
}
void SavingsAccount::settle(Date date)
{
	accumulate(date);
	if (date.isLeapYear(date.getYear() - 1))
	{
		balance += accumulation / 366 * rate;
		total += accumulation / 366 * rate;

	}
	else
	{
		balance += accumulation / 365 * rate;
		total += accumulation / 365 * rate;
	}
}
void Account::show()
{
	cout << "id:" << id << endl << "余额:" << balance << endl;// << "利息:" << accumulation / (365 + lastDate.isLeapYear(lastDate.getYear() - 1)) * rate << endl << endl;
}


void CreditAccount:: withdraw(Date date, double amount)
{
	int d = lastD.distance(date);
	double b;
	b = (balance*rate*d); balance += d;
	balance += amount;
	total -= amount;
	lastD = date;

}
void CreditAccount::settle(Date date){
	int d = lastD.distance(date);
	double b;
	b = (balance*rate*d); balance += b;
	lastD = date;
}
void CreditAccount::repay(Date date, double amount){
	int d = lastD.distance(date);
	double b;
	b = (balance*rate*d); balance += d;
	balance -= amount;
	total += amount;
	lastD = date;
}
void CreditAccount::clear(Date date) { 
	int d = lastD.distance(date);
	double b;
	b = (balance*rate*d); balance += d;
	total += balance;balance = 0;  
	lastD = date;
}
void CreditAccount::show()
{
	cout << "id:" << id << endl << "欠款:" << balance << endl;// << "利息:" << accumulation / (365 + lastDate.isLeapYear(lastDate.getYear() - 1)) * rate << endl << endl;
}