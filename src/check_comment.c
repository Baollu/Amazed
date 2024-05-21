/*
** EPITECH PROJECT, 2024
** check
** File description:
** check
*/

#include "my_macro.h"
#include "my.h"
#include <stddef.h>

int nbr_end(char *data, char *str)
{
    if (my_strcmp(str, "##end") == 0)
        if (data != NULL)
            return 1;
    return 0;
}

int nbr_start(char *data, char *str)
{
    if (my_strcmp(str, "##start") == 0)
        if (data != NULL)
            return 1;
    return 0;
}

int check_comment(char **array)
{
    int start = 0;
    int end = 0;

    for (int i = 1; array[i] != NULL; i++){
        if (nbr_start(array[i], array[i - 1]) == 1)
            start++;
        if (end > start)
            return 1;
        if (nbr_end(array[i], array[i - 1]) == 1)
            end++;
    }
    if (start != 1 || end != 1)
        return 1;
    return 0;
}
