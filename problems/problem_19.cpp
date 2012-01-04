#include "problem_19.hpp"

#include <iostream>

using namespace std;

Date::Date() :
    day(0),
    month(0),
    year(1901),
    dayOfWeek(0)
{
}

void Date::NextMonth()
{
    int nbDays = daysInMonth[month];

    if(month == 1)
    {
        if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            ++nbDays;
        }
    }

    dayOfWeek += nbDays;
    dayOfWeek %= daysInWeek;

    ++month;

    if(month > 11)
    {
        ++year;
        month = 0;
    }
}

int Date::GetDayOfWeek() const
{
    return dayOfWeek;
}

int Date::GetYear() const
{
    return year;
}

int Date::GetMonth() const
{
    return month;
}

int Date::GetDay() const
{
    return day;
}

const int Date::daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int Date::daysInWeek = 7;

int problem_19()
{
    Date d;
    int sum = 0;

    while(d.GetYear() < 2001)
    {
        cout << d.GetDayOfWeek() << " " << d.GetDay() << " " << d.GetMonth() << " " << d.GetYear() << endl;

        d.NextMonth();
        if(d.GetYear() > 1901 && d.GetDayOfWeek() == 6)
            ++sum;
    }

    cout << sum;

    return 0;
}
