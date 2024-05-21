/*
** EPITECH PROJECT, 2024
** find nb
** File description:
** of robots
*/

#include "my_macro.h"
#include "my.h"

int find_robot_number(char **file, room_t **robot_info)
{
    int nb = -1;
    int nbw = 0;

    my_printf("#number_of_robots\n");
    for (int i = 0; file[i] && nb <= 0; i++) {
        nb = my_getnbr(file[i]);
        nbw = nb_word(file[i], ' ');
    }
    (*robot_info)->nb_robot = nb;
    if (nb < 0 || nbw != 1)
        return MY_EXIT_FAILURE;
    my_printf("%d\n", (*robot_info)->nb_robot);
    my_printf("#rooms\n");
    return MY_EXIT_SUCCESS;
}
