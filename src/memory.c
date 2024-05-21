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

memory_t *init_memory(void)
{
    return NULL;
}

void add_to_memory(memory_t **memory, link_t *link)
{
    memory_t *new_memory = malloc(sizeof(memory_t));

    new_memory->link = link;
    new_memory->next = *memory;
    *memory = new_memory;
}

bool is_in_memory(memory_t **start_memory, link_t *link)
{
    memory_t *memory = *start_memory;

    while (memory != NULL){
        if (memory->link == link)
            return true;
        memory = memory->next;
    }
    return false;
}

void free_memory(memory_t *memory)
{
    if (memory->next != NULL)
        free_memory(memory->next);
    free(memory);
}
