#ifndef MAIN_VIEW_CPP
#define MAIN_VIEW_CPP
#include <iostream>

#define ERR_SUCCESS 0
#define ERR_OPEN_FILE_FAIL 1
#define ERR_INCORRECT_SIZES 2
#define ERR_INCORRECT_INPUT 3
#define ERR_EMPTY_DATA 4

/// <summary>
/// Вывод ответа
/// </summary>
/// <param name="isDisplayable">Можно ли отобразить</param>
inline void PrintData(bool isDisplayable){
    std::cout << (isDisplayable ? "Yes" : "No")<<'\n';
}
/// <summary>
/// Вывод обрабатываемых данных
/// </summary>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <param name="tablo">табло</param>
/// <param name="img">заставка</param>
inline void PrintData(int n, int m, const char* tablo, const char* img) {
    std::cout << n << ' ' << m << "\n";
    for (int i = 0; i < n * m; ++i) {
        if (i % n == 0)std::cout << '\n';
        std::cout << (int)img[i];
    }
    std::cout << "\n";
    for (int i = 0; i < n*m; ++i) {
        if (i % n == 0)std::cout << '\n';
        std::cout << (int)tablo[i];
    }
}
/// <summary>
/// Выводит сообщение ошибки
/// </summary>
/// <param name="error">код ошибки</param>
inline void describError(char error) {
    switch (error)
    {
    case ERR_INCORRECT_SIZES:       std::cout << '(' << (int)error << ")Error:" << "ERR_INCORRECT_SIZES" << '\n';break;
    case ERR_OPEN_FILE_FAIL:        std::cout << '(' << (int)error << ")Error:" << "ERR_OPEN_FILE_FAIL" << '\n';break;
    case ERR_EMPTY_DATA:            std::cout << '(' << (int)error << ")Error:" << "ERR_EMPTY_DATA" << '\n';break;
    case ERR_INCORRECT_INPUT:       std::cout << '(' << (int)error << ")Error:" << "ERR_INCORRECT_INPUT" << '\n';break;
    }
}

#endif  MAIN_VIEW_CPP
