#include <iostream>
#include "Menu.h"
#include "Input.h"
#include "Model.h"
#include "View.h"

char tablo[10000];
char image[10000];
int n, m;
int main()
{
    n = m = 0;
    int com;
    do {
        com = getCommand();
        switch (com) {
        case MENU_FILE_INPUT:
            describError(getInput(getParameters("File's name: "), n, m, tablo, image));
            break;
        case MENU_CONSOLE_INPUT:
            describError(getInput(n, m, tablo, image));
            break;
        case MENU_IS_DISPLAYABLE:
            if (n) PrintData(IsDislplayable(n, m, tablo, image));
            else describError(ERR_EMPTY_DATA);
            break;
        case MENU_PRINT_DATA:
            if (n) PrintData(n, m, tablo, image); 
            else  describError(ERR_EMPTY_DATA);
            break;
        }
    } while (com);
    return 0;
}
