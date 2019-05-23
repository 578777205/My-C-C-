#include<iostream>
#include<string>
#include"account.h"
#include"date.h"

using namespace std;
int main()
{
	SavingsAccount s0(2008,11,1, 1, 0.015);
	SavingsAccount s1(2008,11,1, 2, 0.015);
	CreditAccount c0(3,10000,0.0005,50,2008,11,1);

	s0.deposit(Date(2008,11,5), 5000);
	s0.deposit(Date(2008,12,5), 5500);
	s1.deposit(Date(2008,11,25), 10000);
	s1.withdraw(Date(2008,12,20), 4000);
	c0.withdraw(Date(2008, 11, 5), 2000);
	c0.clear(Date(2008,12,1));
    c0.settle((Date(2009, 1, 1)));
	s0.settle(Date(2009, 1, 1)); s1.settle(Date(2009, 1, 1));
	
	s0.show(); s1.show(); 
	c0.show();
	cout << "×Ü¼Æ" << SavingsAccount::getTotal()<< endl;
	return 0;
}
