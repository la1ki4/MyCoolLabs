#include <iostream>

struct Date
{

private:
    //Инициализируем поля day, month, year
    int day;
    int month;
    int year;

public:

    //Инициализурем конструктор без параметров, чтобы в полях не лежал мусор
    Date()
    {
        this->day = 0;
        this->month = 0;
        this->year = 0;
    }


    //Конструктор копирования
    Date(const Date& dateParameters)
    {
        this->day = dateParameters.day;
        this->month = dateParameters.month;
        this->year = dateParameters.year;
    }

    //Оператор присваивания
    Date& operator=(const Date& date)
    {
        this->day = date.day;
        this->month = date.month;
        this->year = date.year;

        return *this;
    }

    //Оператор сравнения
    bool operator==(const Date& firstDate)
    {
        return this->day == firstDate.day && this->month == firstDate.month && this->year == firstDate.year;
    }

    //прототип перегрузки оператора записи в поток
    friend std::ostream& operator<<(std::ostream& out, const Date& date);

    //Прототип перегрузки оператора чтения из потока
    friend std::istream& operator>>(std::istream& in, Date& date);
};

//Реализация перегрузки оператора записи в поток
std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << date.day << "/" << date.month << "/" << date.year;

    return out;
}

//Реализация перегрузки оператора чтения из потока
std::istream& operator>>(std::istream& in, Date& date)
{
    char delimeter;
    in >> date.day >> delimeter >> date.month >> delimeter >> date.year;

    return in;
}
