#ifndef  _DATE_H_  
#define  _DATE_H_ 

#include<iostream>
class  Date
{
	int  year, month, day;
	int  totalDays;   //该日期是从公元元年1月1日开始的第几天
public:
	Date(int year, int month, int day);
	int gettotal() const{ return totalDays; }
	int  getYear() const { return year; }
	int  getMonth() const { return month; }
	int  getDay() const { return day; }
	void  show() const;			//输出当前日期
	bool isLeapYear(int y) const;
	int  distance(const Date& date) const;//计算当前日期与指定日期之间相差天数
};

#endif              
#pragma once
