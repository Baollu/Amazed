/*
** EPITECH PROJECT, 2024
** init
** File description:
** robot info
*/
#include <stddef.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

room_t *init_robot_info(void)
{
    room_t *tmp = malloc(sizeof(room_t));

    if (tmp == NULL)
        return NULL;
    tmp->posx = 0;
    tmp->posy = 0;
    tmp->nb_robot = 0;
    tmp->room = 0;
    tmp->room_type = DEFAULT;
    tmp->next = NULL;
    return tmp;
}
