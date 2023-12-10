#include <iostream>

struct WrongDayException
{
    int day;
};

struct WrongMonthException
{
    int month;
};

struct WrongYearException
{
    int year;
};

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
        if (year < 0)
        {
            throw WrongYearException{ year };
        }

        int daysInMonth = DaysInMonth(year, month);

        if (day > daysInMonth || day <= 0)
        {
            throw WrongDayException{ day };
        }

        if (month > 12 || month <= 0)
        {
            throw WrongMonthException{ month };
        }
       // Normalize();
    }

    Date(int day) : day(day), month(1), year(0)
    {
        if (day <= 0) {
            throw WrongDayException{ day };
        }
       // Normalize();
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

    // перегрузка операторов +, - и +=

    Date operator+(int d) const
    {
        int chDay = day + d;
        return Date(chDay, month, year);
    }

    Date operator-(int d) const
    {
        int chDay = day - d;
        return Date(chDay, month, year);
    }

    Date& operator+=(int d)
    {
        day += d;
        Normalize();
        return *this;
    }
};

// перегрузка операторов << и >> для Date

std::ostream & operator<<(std::ostream & out, const Date & d)
{
    out << d.GetDay() << " . " << d.GetMonth() << " . " << d.GetYear();
    return out;
}

std::istream& operator >> (std::istream& in, Date& date)
{
    std::cin.exceptions(std::istream::failbit);

    int y, m, d;
    char c;

    in >> d >> c;
    in >> m >> c;
    in >> y;

    date = Date(d, m, y);

    return in;

}

int main()
{
    
        
    return 0;
}