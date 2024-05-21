/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main fonction
*/

#include <stddef.h>
#include "my_macro.h"
#include "my.h"

int amazed(int ac)
{
    paths_t *tunnels = init_tunnels();
    room_t *robot_info = init_robot_info();
    int rt = robustness(ac, &robot_info, &tunnels);

    if (rt == 1)
        return MY_EXIT_FAILURE;
    if (rt == 3)
        return MY_EXIT_SUCCESS;
    print_shortest_path(robot_info, tunnels);
    return MY_EXIT_SUCCESS;
}
