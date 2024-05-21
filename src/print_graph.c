/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

static void print_graph_link(link_t *link, memory_t **memory)
{
    print_link(link);
    add_to_memory(memory, link);
    for (int i = 0; link->next[i] != NULL; i++)
        if (!is_in_memory(memory, link->next[i]))
            print_graph_link(link->next[i], memory);
}

void print_graph(link_t *base_link)
{
    memory_t *memory = init_memory();

    print_graph_link(base_link, &memory);
    free_memory(memory);
}
