/*
** EPITECH PROJECT, 2024
** init
** File description:
** struct
*/
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

paths_t *init_tunnels(void)
{
    paths_t *tmp = malloc(sizeof(paths_t));

    tmp->path1 = NULL;
    tmp->path2 = NULL;
    tmp->next = NULL;
    return tmp;
}

int print_all_tunnels(paths_t *tunnels)
{
    paths_t *tmp = tunnels;

    if (!tmp)
        return 1;
    my_printf("#tunnels\n");
    for (; tmp; tmp = tmp->next) {
        if (!tmp)
            return 1;
        my_printf("%s-%s\n", tmp->path1, tmp->path2);
    }
    return 0;
}
