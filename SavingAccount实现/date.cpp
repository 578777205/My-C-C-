#include <iostream>
#include "date.h"

using namespace std;
int Month[] = { 0,31,59,90,120,151,181,212,243,73,304,334,365 };

Date::Date(int year, int month, int day) :year(year), month(month), day(day)
{
	int count = 0, sum = 0;
	for (int i = 1; i < year; i++)
	{
		if (isLeapYear(i))
		{
			count++;
		}
	}

	totalDays = (year - 1) * 365 + count + Month[this->month - 1] + day - 1;
};

void Date::show() const
{
	cout << getYear() << "Äê" << getMonth() << "ÔÂ" << getDay() << "Ìì" << endl;
	return;
}

bool Date::isLeapYear(int y) const
{

	if (y < 4)
	{
		return 0;
	}
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}

int Date::distance(const Date& date) const
{
	return date.totalDays - this->totalDays;
}
