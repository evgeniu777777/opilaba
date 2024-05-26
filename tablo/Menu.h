#ifndef MENU_CPP
#define MENU_CPP
#include "Menu.h"
#include "View.h"
#include <iostream>

#define MENU_EXIT 0
#define MENU_FILE_INPUT 1
#define MENU_CONSOLE_INPUT 2
#define MENU_IS_DISPLAYABLE 3
#define MENU_PRINT_DATA 4

/// <summary>
/// Интерфейс взаимодействия с пользователем
/// </summary>
/// <returns>Пользовательская команда</returns>
inline int getCommand()
{
    char choice;
    do {
        std::cout << "\nYou can:\n1. Input file data\n2. Input console data\n3. Can it display\n4. Print data\n0. Exit\nYour choice:\n";
        std::cin >> choice;
        choice -= '0';
    } while ((choice < MENU_EXIT) || (choice > MENU_PRINT_DATA));
    return choice;
}
/// <summary>
/// Выводит сообщение и возвращает ввод пользователя через консоль
/// </summary>
/// <param name="ques">сообщение</param>
/// <returns>Пользовательский ввод </returns>
inline const char* getParameters(const char* ques) {
    std::cout << ques;
    static char data[200];
    std::cin.getline(data, 200);std::cin.getline(data, 200);
    return data;
}
#endif  MENU_CPP
