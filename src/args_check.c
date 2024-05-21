/*
** EPITECH PROJECT, 2024
** args
** File description:
** check
*/

#include "my_macro.h"
#include "my.h"

int args_check(int ac)
{
    if (ac != 1)
        return 1;
    return MY_EXIT_SUCCESS;
}
