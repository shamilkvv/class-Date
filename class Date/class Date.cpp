#include <iostream>

class Date
{
private:
    int year;
    int month;
    int day;

    //функция используется определения, является ли указанный год високосным

    static bool IsLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    //возвращает количество дней в указанном месяце для указанного года

    static int DaysInMonth(int year, int month)
    {
        static const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        return (month == 2 && IsLeapYear(year)) ? 29 : daysInMonth[month];
    }

    // корректное представление даты

    void Normalize()
    {
        if (month != 12)
        {
            year += month / 12;
            month %= 12;
        }

        if (month < 1)
        {
            month = 12 + month;
            year--;
        }

        while (day > DaysInMonth(year, month))
        {
            day -= DaysInMonth(year, month);
            month++;

            if (month > 12)
            {
                year++;
                month = 1;
            }
        }

        while (day <= 0)
        {
            month--;

            if (month < 1)
            {
                year--;
                month = 12;
            }

            day += DaysInMonth(year, month);
        }
    }

public:

    // конструкторы

    Date(int day, int month, int year) : day(day), month(month), year(year)
    {
        Normalize();
    }

    Date(int day) : day(day), month(0), year(1)
    {
        Normalize();
    }

    int GetYear() const
    {
        return year;
    }

    int GetMonth() const
    {
        return month;
    }

    int GetDay() const
    {
        return day;
    }
};

int main()
{
    
        
    return 0;
}