/*
** EPITECH PROJECT, 2024
** robustess
** File description:
** tests
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_macro.h"
#include "my.h"

char *fill_buffer(void)
{
    size_t size = 0;
    char *tmp = 0;
    char *buffer = NULL;
    int nb = 1;
    int save = 0;

    getline(&tmp, &size, stdin);
    buffer = my_strdup(tmp);
    while (nb) {
        nb = getline(&tmp, &size, stdin);
        if (nb == -1)
            break;
        save = save + nb;
        buffer = my_strcat_j(buffer, tmp);
    }
    buffer = my_strcat_j(buffer, "");
    return buffer;
}

int nb_char(char *str, char ref)
{
    int nb_ref = 0;

    for (int i = 0; str[i]; i += 1) {
        if (str[i] == ref)
            nb_ref++;
    }
    return nb_ref;
}

int check_tunnels(char **str)
{
    int nb_w = 0;
    char **tunnels = NULL;
    int nb_tunnel = 0;

    for (int i = 0; str[i]; i++) {
        nb_w = nb_word(str[i], '-');
        if (nb_w != 2)
            continue;
        tunnels = my_str_to_word_array(str[i], '-');
        if ((tunnels[0] && tunnels[1]) && nb_char(str[i], '-') == 1)
            nb_tunnel++;
    }
    if (nb_tunnel < 3)
        return 1;
    for (int i = 0; tunnels[i]; i++)
        free(tunnels[i]);
    return 0;
}

int robustness(int ac, room_t **robot_info, paths_t **tunnels)
{
    char *buffer;
    char **str = NULL;
    int rt = 0;

    if (args_check(ac))
        return 1;
    buffer = fill_buffer();
    str = my_str_to_word_array(buffer, '\n');
    if (my_strlen(buffer) <= 2)
        return 1;
    str = delete_comment(str);
    if (find_robot_number(str, robot_info))
        return 1;
    rt = find_start_end(str, robot_info);
    if (rt == 3)
        return 3;
    if (rt == 1 || add_tunnels(str, tunnels))
        return 3;
    return 0;
}
