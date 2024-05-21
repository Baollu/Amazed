/*
** EPITECH PROJECT, 2023
** task
** File description:
** 2
*/
#include "my.h"

char *my_strcpy_j(char *dest, const char *src, int i)
{
    int bis = 0;

    while (src[bis] != '\0') {
        dest[bis + i] = src[bis];
        bis++;
    }
    dest[i + bis] = '\0';
    return dest;
}
