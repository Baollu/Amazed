/*
** EPITECH PROJECT, 2024
** push
** File description:
** tunnels
*/
#include <stddef.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

void push_tunnels(char **words, paths_t **tunnels)
{
    paths_t *current = *tunnels;
    paths_t *element = NULL;

    my_printf("%s-%s\n", words[0], words[1]);
    if (!current->path1) {
        current->path1 = my_strdup(words[0]);
        current->path2 = my_strdup(words[1]);
        current->next = NULL;
        return;
    }
    element = malloc(sizeof(paths_t));
    for (; current->next != NULL; current = current->next);
    element->path1 = my_strdup(words[0]);
    element->path2 = my_strdup(words[1]);
    element->next = NULL;
    current->next = element;
}
