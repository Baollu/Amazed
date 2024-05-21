/*
** EPITECH PROJECT, 2024
** is
** File description:
** room
*/
#include <stdbool.h>
#include "my_macro.h"
#include "my.h"

bool verif_room_exist(room_t *robot_info, char **words)
{
    room_t *tmp = robot_info->next;

    for (; tmp; tmp = tmp->next) {
        if ((my_strcmp(words[0], tmp->room) == 0)
            || (my_strcmp(words[1], tmp->posx) == 0
            && my_strcmp(words[2], tmp->posy) == 0))
            return true;
    }
    return false;
}

int is_room(char **words, room_t **robot_info, char *ref)
{
    int nb_str = 0;

    nb_str = nb_of_pointers(words);
    if (nb_str >= 3) {
        if (verif_room_exist(*robot_info, words))
            return MY_EXIT_SUCCESS;
        push_to_list(words, robot_info, ref);
    }
    return MY_EXIT_SUCCESS;
}
