#ifndef  _ACCOUNT_H_  
#define  _ACCOUNT_H_

#include<iostream>
#include"date.h"
class Account
{
protected:
	int  id;  //�ʺ�
	double  balance = 0;	 //��� 
	static double total;//�ܽ��
public:
	Account(int id) :id(id) {};
	void  show();	  //����˻���Ϣ
	static double getTotal() { return total; };
	int getId() const { return id; }
	double  getBalance() const { return balance; }
};


class SavingsAccount:public Account
{
	double  rate;	  //������
	Date  lastDate;	//�ϴα����������
	double  accumulation = 0;	//�����ۼ�֮��
	double  accumulate(Date date);//��õ�ָ������Ϊֹ�Ĵ������ۻ�ֵ
public:
	SavingsAccount(int year, int month, int day, int id, double rate) :Account(id), lastDate(year, month, day), rate(rate) {};  //���캯��
	void  deposit(Date date, double amount);  //�����ֽ�dateΪ���ڣ�amountΪ���
	void  withdraw(Date date, double amount);  //ȡ���ֽ�
	void  settle(Date date);	//������Ϣ��ÿ��1��1�յ���һ�θú���	

	double  getRate() const { return rate; }
};

class  CreditAccount:public Account
{

	double  credit;   //���ö��
	double  rate;    //Ƿ���������
	double  fee;    //���ÿ����
	Date lastD;
	double  getDebt() const { return balance; };   //���Ƿ���
public:
	CreditAccount(int id,double credit, double rate, double fee, int year, int month, int day) :credit(credit),rate(rate),fee(fee),Account(id), lastD(year, month, day) {};
	double  getAvailableCredit() const {return credit;};  //��ÿ������ö��
	using Account::show;
	void withdraw(Date date, double amount);//ȡǮ����
	void repay(Date date, double amount);//�����
	void clear(Date date);
	void settle(Date date);
	void show();
};


#endif
#pragma once
