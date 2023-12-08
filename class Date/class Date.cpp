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

public:

    // конструкторы

    Date(int day, int month, int year) : day(day), month(month), year(year)
    {

    }

    Date(int day) : day(day), month(0), year(1)
    {

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