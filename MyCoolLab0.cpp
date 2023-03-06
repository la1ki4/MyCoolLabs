#include <iostream>
#include "ParticipantOfTheCompetition.hpp"
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>



int main()
{

    std::string path = "MOCK_DATA.csv";

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
            
            
            unsigned short countOfParticipants = 0;

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

                    countOfParticipants++;
                }
                
                //Создаём копию списка участников соревнования
                std::vector<ParticipantOfTheCompetition> copyOfList;
                
                //Переносим из оригинального списка участника в копию списка участников
                copyOfList = Participants;
                
                //Выводим всех участников соревнования
                std::cout << "Copied list: " << std::endl;

                for(unsigned short i = 0; i < copyOfList.size(); i++)
                {
                    std::cout << copyOfList[i];
                }

                std::cout << "\n\n\n";
                
                //Проверяем если ID меньше или равен количеству участников
                if(idParticipant <= countOfParticipants)
                {
                    //Пробегаемся по всем участникам в списке
                    for (unsigned short i = 0; i < Participants.size(); i++)
                    {
                        //Если такой участник найден, выводим его в консоле
                        if (Participants[i] == idParticipant)
                        {
                            std::cout << "Participant with ID: " << idParticipant;
                            std::cout << Participants[i];
                            break;
                        }
                    }
                }
                
                //Если же ID участника больше, чем количество участников...
                else if (idParticipant > countOfParticipants)
                {
                    std::cout << "There is no participant with ID: " << idParticipant;
                }
            }
            
            //Если же ID участника имеет отрицательное значение...
            else if (idParticipant <= 0)
            {
                std::cout << "ID " << idParticipant << " cannot exist! Your ID has a negative value.";
            }
            
            
    }
    file.close();

    system("pause>nul");
    return 0;
}
