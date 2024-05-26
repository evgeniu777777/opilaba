#ifndef INPUT_H
#define INPUT_H
/// <summary>
/// Ввод обрабатываемых данных из консоли
/// </summary>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <param name="tablo">табло</param>
/// <param name="image">заставка</param>
/// <returns>Код ошибки или успех</returns>
char getInput(int& n, int& m,char* tablo, char* image);
/// <summary>
/// Ввод обрабатываемых данных из файла
/// </summary>
/// <param name="file_name">целевой файл</param>
/// <param name="n">кол-во строк</param>
/// <param name="m">кол-во столбцов</param>
/// <param name="tablo">табло</param>
/// <param name="image">заставка</param>
/// <returns>Код ошибки или успех</returns>
char getInput(const char* file_name, int& n, int& m, char* tablo, char* image);
#endif INPUT_H

