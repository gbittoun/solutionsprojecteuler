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

int problem_19();
