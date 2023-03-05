#include <iostream>
#include "ParticipantOfTheCompetition.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>



int main()
{
    setlocale(LC_ALL, "Rus");

    std::string path = "C:/MyCoolProjects/MyCoolProject0/MOCK_DATA.csv";

    std::ifstream file(path);

    std::vector<ParticipantOfTheCompetition> Participants;

    //Проверка на открытие файла
    if (!file.is_open())
    {
        std::cout << "File opening error!" << std::endl;
    }
    else
    {
        
            std::cout << "Enter the contestant's ID: ";
            short idParticipant;
            std::cin >> idParticipant;
            
            
            int countOfParticipants = 0;

            if (idParticipant > 0)
            {
                //Пока файл не дошёл до конца
                while (!file.eof())
                {
                    //Создаём временную переменную
                    ParticipantOfTheCompetition tmp;

                    //Считываем из файла значения во временную переменную
                    file >> tmp;

                    //Если достигнут конец файла, завершаем работу цикла
                    if (file.eof())
                    {
                        break;
                    }
                    //Записываем участника в список
                    Participants.push_back(tmp);

                    //считаем сколько всего участников есть
                    countOfParticipants++;
                }

                
                if (idParticipant > countOfParticipants)
                {
                    std::cout << "There is no participant with this ID!";
                }

                //Пробегаемся по всем участникам в списке
                for (int i = 0; i < Participants.size(); i++)
                {
                    //Если такой участник найден, выводим его в консоле
                    if (Participants[i] == idParticipant)
                    {
                        std::cout << Participants[i];
                        break;
                    }
                }

            }

            else if (idParticipant <= 0)
            {
                std::cout << "This ID cannot exist!";
            }
            
            
    }
    std::vector<ParticipantOfTheCompetition> copyOfList;
    copyOfList = Participants;

    std::cout << "\n\n\n";
    std::cout << "Copied list: " << std::endl;
    std::cout << copyOfList[6];

    file.close();


    system("pause>nul");
    return 0;
}