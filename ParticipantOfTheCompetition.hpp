#include <iostream>
#include <sstream>
#include <string>
#include "Date.hpp"

class ParticipantOfTheCompetition : public Date
{

private:
    //Инициализируем поля из варианта структуры
    std::string lastName;
    std::string firstName;
    std::string country;
    std::string category;
    Date birthYear;
    short idNumberInTable;

public:
    //Инициализируем конструктор по умолчанию
    ParticipantOfTheCompetition()
    {
        this->lastName = "\0";
        this->firstName = "\0";
        this->category = "\0";
        this->country = "\0";
        idNumberInTable = 0;
    }


    //Инициализируем конструктор копирования
    ParticipantOfTheCompetition(const ParticipantOfTheCompetition& participant)
    {
        this->lastName = participant.lastName;
        this->firstName = participant.firstName;
        this->country = participant.country;
        this->category = participant.category;
        this->birthYear = participant.birthYear;
        this->idNumberInTable = participant.idNumberInTable;
    }

    //Деструктор
    virtual ~ParticipantOfTheCompetition()
    {

    }

    //перегрузка оператора присваивания
    ParticipantOfTheCompetition& operator=(const ParticipantOfTheCompetition& newPartcipant)
    {
        lastName = newPartcipant.lastName;
        firstName = newPartcipant.firstName;
        country = newPartcipant.country;
        category = newPartcipant.category;
        birthYear = newPartcipant.birthYear;
        idNumberInTable = newPartcipant.idNumberInTable;


        return *this;
    }


    //перегрузка оператора сравнения
    bool operator==(const short& id)
    {
        return this->idNumberInTable == id;
    }

    //прототип перегрузки оператора записи в поток
    friend std::ostream& operator<<(std::ostream& out, const ParticipantOfTheCompetition& Participant);

    //прототип перегрузки оператора чтения из потока
    friend std::istream& operator>>(std::istream& in, ParticipantOfTheCompetition& Participant);
};

//перегрузка оператора записи в поток
std::ostream& operator<<(std::ostream& out, const ParticipantOfTheCompetition& Participant)
{
    out << Participant.lastName << "\t" << Participant.firstName << "\t" << Participant.country << "\t" << Participant.category << "\t" << Participant.birthYear << "\t" << Participant.idNumberInTable;

    return out;
}

//перегрузка оператора чтения из потока
std::istream& operator>>(std::istream& in, ParticipantOfTheCompetition& Participant)
{
    getline(in, Participant.lastName, ',');
    getline(in, Participant.firstName, ',');
    getline(in, Participant.country, ',');
    getline(in, Participant.category, ',');
    in >> Participant.birthYear;
    in.ignore();
    in >> Participant.idNumberInTable;

    return in;
}