#ifndef  _ACCOUNT_H_  
#define  _ACCOUNT_H_

#include<iostream>
#include"date.h"
class Account
{
protected:
	int  id;  //帐号
	double  balance = 0;	 //余额 
	static double total;//总金额
public:
	Account(int id) :id(id) {};
	void  show();	  //输出账户信息
	static double getTotal() { return total; };
	int getId() const { return id; }
	double  getBalance() const { return balance; }
};


class SavingsAccount:public Account
{
	double  rate;	  //年利率
	Date  lastDate;	//上次变更余额的日期
	double  accumulation = 0;	//余额按日累加之和
	double  accumulate(Date date);//获得到指定日期为止的存款金额按日累积值
public:
	SavingsAccount(int year, int month, int day, int id, double rate) :Account(id), lastDate(year, month, day), rate(rate) {};  //构造函数
	void  deposit(Date date, double amount);  //存入现金，date为日期，amount为金额
	void  withdraw(Date date, double amount);  //取出现金
	void  settle(Date date);	//结算利息，每年1月1日调用一次该函数	

	double  getRate() const { return rate; }
};

class  CreditAccount:public Account
{

	double  credit;   //信用额度
	double  rate;    //欠款的日利率
	double  fee;    //信用卡年费
	Date lastD;
	double  getDebt() const { return balance; };   //获得欠款额
public:
	CreditAccount(int id,double credit, double rate, double fee, int year, int month, int day) :credit(credit),rate(rate),fee(fee),Account(id), lastD(year, month, day) {};
	double  getAvailableCredit() const {return credit;};  //获得可用信用额度
	using Account::show;
	void withdraw(Date date, double amount);//取钱函数
	void repay(Date date, double amount);//还款函数
	void clear(Date date);
	void settle(Date date);
	void show();
};


#endif
#pragma once
