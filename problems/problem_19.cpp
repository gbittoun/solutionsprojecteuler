#include <iostream>

using namespace std;


class Date
{
    int day;
    int month;
    int year;

    int dayOfWeek;

    static const int daysInMonth[];
    static const int daysInWeek;

    public :

    Date();

    void NextMonth();
    int GetDayOfWeek() const;
    int GetYear() const;
    int GetMonth() const;
    int GetDay() const;
};

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

int main()
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
