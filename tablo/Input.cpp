#include "Input.h"
#include <iostream>
#include <fstream>
#include "View.h"
using namespace std;
inline bool isCorrectSizes(int n,int m) {
    return (0 < n && 0 < m && n < 101 && m < 101);
}
inline bool isValidTablo(char ch) {
    return ch >= '0' && ch < '8';
}
inline char normalizeImage(char ch) {
    switch (ch)
    {
    case'.':return 0;
    case 'B': return 1;
    case 'G':return 2;
    case 'R':return 4;
    }
    return -1;
}

char getInput(const char* file_name, int& N, int& M, char* tablo, char* img)
{
    ifstream f(file_name);
    if(!f)return ERR_OPEN_FILE_FAIL;
    int n, m;   
    N = M = 0;
    f >> n >> m;
    if (!isCorrectSizes(n, m))  return ERR_INCORRECT_SIZES; 
    for (int i = 0; i < n * m; ) {
        if (!(f >> img[i])) return ERR_INCORRECT_INPUT;
        if (img[i] == ' ' || img[i] == '\n')continue;
        img[i] = normalizeImage(img[i]);
        if (img[i] == -1) return ERR_INCORRECT_INPUT;
        ++i;
    }
    for (int i = 0; i < n * m; ) {
        if (!(f >> tablo[i]))  return ERR_INCORRECT_INPUT;
        if (tablo[i] == ' ' || tablo[i] == '\n')continue;
        if (!isValidTablo(tablo[i]))  return ERR_INCORRECT_INPUT;
        tablo[i] -= '0';
        ++i;
    }
    N = n;
    M = m;
    return ERR_SUCCESS;
}

char getInput(int& N, int& M, char* tablo, char* img)
{
    int n, m;
    N = M = 0;
    cin >> n >> m;
    if (!isCorrectSizes(n, m))  return ERR_INCORRECT_SIZES;
    for (int i = 0; i < n * m; ) {
        cin >> img[i];
        if (img[i] == ' ' || img[i] == '\n')continue;
        img[i] = normalizeImage(img[i]);
        if (img[i] == -1)return ERR_INCORRECT_INPUT; 
        ++i;
    }
    for (int i = 0; i < n * m; ) {
        cin >> tablo[i];
        if (tablo[i] == ' ' || tablo[i] == '\n')continue;
        if (!isValidTablo(tablo[i])) return ERR_INCORRECT_INPUT; 
        ++i;
    }
    N = n;
    M = m;
    return ERR_SUCCESS;
}
