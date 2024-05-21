/*
** EPITECH PROJECT, 2024
** print
** File description:
** print
*/

#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

void print_room(room_t *room)
{
    my_printf("room: %s, pos: %s %s, type: %d\n",
        room->room, room->posx, room->posy, room->room_type);
}

int print_start(room_t *tmp)
{
    if (!tmp)
        return 1;
    my_printf("##start\n");
    for (; tmp; tmp = tmp->next) {
        if (!tmp)
            return 1;
        if (tmp->room_type == START)
            my_printf("%s %s %s\n", tmp->room, tmp->posx, tmp->posy);
    }
    return 0;
}

int print_end(room_t *tmp)
{
    my_printf("##end\n");
    if (!tmp)
        return 1;
    for (; tmp; tmp = tmp->next) {
        if (!tmp)
            return 1;
        if (tmp->room_type == END)
            my_printf("%s %s %s\n", tmp->room, tmp->posx, tmp->posy);
    }
    return 0;
}

int print_rooms(room_t *tmp)
{
    if (!tmp)
        return 1;
    for (; tmp; tmp = tmp->next) {
        if (!tmp)
            return 1;
        if (tmp->room_type == DEFAULT)
            my_printf("%s %s %s\n", tmp->room, tmp->posx, tmp->posy);
    }
    return 0;
}

int print_all_room(room_t *room)
{
    room_t *tmp = room->next;

    if (!room)
        return 1;
    if (!room->next)
        return 1;
    if (room->next->room_type == DEFAULT)
        my_printf("%s %s %s\n",
            room->next->room, room->next->posx, room->next->posy);
    if (print_start(tmp))
        return 1;
    tmp = room->next;
    if (print_end(tmp))
        return 1;
    tmp = room->next->next;
    print_rooms(tmp);
    return 0;
}
