#ifndef  _DATE_H_  
#define  _DATE_H_ 

#include<iostream>
class  Date
{
	int  year, month, day;
	int  totalDays;   //�������Ǵӹ�ԪԪ��1��1�տ�ʼ�ĵڼ���
public:
	Date(int year, int month, int day);
	int gettotal() const{ return totalDays; }
	int  getYear() const { return year; }
	int  getMonth() const { return month; }
	int  getDay() const { return day; }
	void  show() const;			//�����ǰ����
	bool isLeapYear(int y) const;
	int  distance(const Date& date) const;//���㵱ǰ������ָ������֮���������
};

#endif              
#pragma once
