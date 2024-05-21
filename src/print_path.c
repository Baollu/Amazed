/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main fonction
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int get_path_len(char **path)
{
    int len = 0;

    for (len = 0; path[len] != NULL; len++);
    return len;
}

static char **rev_str_arr(char **arr)
{
    int arr_len = get_path_len(arr);
    char **new_arr = malloc(sizeof(char *) * (arr_len + 1));

    for (int i = 0; arr[i] != NULL; i++)
        new_arr[arr_len - i - 1] = arr[i];
    new_arr[arr_len] = NULL;
    return new_arr;
}

static char **get_path(link_t **links)
{
    link_t *node = get_start(links);
    int base_dist = node->dist;
    char **path = malloc(sizeof(char *) * (base_dist + 1));

    for (int i = 0; node->dist != 0; i++){
        node = get_closest(node);
        path[i] = node->name;
    }
    path[base_dist - 1] = node->name;
    path[base_dist] = NULL;
    path = rev_str_arr(path);
    return path;
}

static int *get_robot(int path_len)
{
    int *robot = malloc(sizeof(int) * (path_len + 1));

    for (int i = 0; i < path_len; i++)
        robot[i] = i + 1;
    robot[path_len] = -1;
    return robot;
}

void print_path(link_t **links, int nbr_robot)
{
    char **path = get_path(links);
    int path_len = get_path_len(path);
    int *robot = get_robot(nbr_robot);

    my_printf("#moves\n");
    path += path_len - 1;
    for (int i = 0; i < nbr_robot + path_len - 1; i++){
        for (int j = 0; path[j] != NULL && robot[j] != -1; j++)
            my_printf((j != 0 ? " P%d-%s" : "P%d-%s"), robot[j], path[j]);
        my_printf("\n");
        if (i < path_len - 1)
            path--;
        else
            robot++;
    }
}
