/*
** EPITECH PROJECT, 2024
** push info
** File description:
** in struct
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_macro.h"
#include "my.h"

void push_to_list(char **words, room_t **robot_info, char *ref)
{
    room_t *current = *robot_info;
    room_t *element = NULL;

    element = malloc(sizeof(room_t));
    for (; current->next != NULL; current = current->next);
    element->room = my_strdup(words[0]);
    element->posx = my_strdup(words[1]);
    element->posy = my_strdup(words[2]);
    element->room_type = DEFAULT;
    element->next = NULL;
    if (my_strcmp(ref, "start") == 0) {
        my_printf("##start\n");
        element->room_type = START;
    }
    if (my_strcmp(ref, "end") == 0) {
        my_printf("##end\n");
        element->room_type = END;
    }
    my_printf("%s %s %s\n", element->room, element->posx, element->posy);
    current->next = element;
}
