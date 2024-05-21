/*
** EPITECH PROJECT, 2024
** robustess
** File description:
** tests
*/
#include <stddef.h>
#include "my_macro.h"
#include "my.h"

void remove_comment(int i, char **str)
{
    int c = 0;

    if (my_grep(str[i], "##"))
        return;
    for (; str[i][c] != '#' && str[i][c] != '\0'; c++);
    for (; str[i][c] != '\0'; c++) {
        str[i][c] = ' ';
    }
}

char **delete_comment(char **str)
{
    for (int i = 0; str[i]; i++) {
        if (!str[i])
            return 0;
        if (my_grep(str[i], "#")) {
            remove_comment(i, str);
        }
    }
    return str;
}
