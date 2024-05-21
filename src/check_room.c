/*
** EPITECH PROJECT, 2024
** check
** File description:
** check
*/

#include "my_macro.h"
#include "my.h"
#include <stddef.h>
#include <stdio.h>

int check_coordonne(room_t *room)
{
    room_t *next = room->next;

    while (next != NULL){
        if (my_strcmp(room->posx, next->posx) == 0
            && my_strcmp(room->posy, next->posy) == 0)
            return 1;
        next = next->next;
    }
    return 0;
}

int check_name_room(room_t *room)
{
    room_t *next = room->next;

    while (next != NULL){
        if (my_strcmp(room->room, next->room) == 0)
            return 1;
        next = next->next;
    }
    return 0;
}

int check_value_room_start_end(room_t *room)
{
    if (room->room_type == START)
        if (!room->room)
            return 1;
    if (room->room_type == END)
        if (!room->room)
            return 1;
    return 0;
}

int check_data(room_t **room_info)
{
    room_t *tmp = (*room_info)->next;

    if (tmp->room == NULL)
        return 1;
    while (tmp != NULL){
        if (check_value_room_start_end(tmp))
            return 1;
        if (check_coordonne(tmp))
            return 1;
        if (check_name_room(tmp))
            return 1;
        tmp = tmp->next;
    }
    return 0;
}
