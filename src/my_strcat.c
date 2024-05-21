/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** game in terminal
*/
#include <stdlib.h>
#include "my.h"

char *my_strcat_j(char *add, char *str)
{
    int len = my_strlen(str);
    int len2 = my_strlen(add);
    char *new = malloc(sizeof(char) * (len + len2 + 1));

    new = my_strcpy_j(new, add, 0);
    new = my_strcpy_j(new, str, len2);
    return new;
}
