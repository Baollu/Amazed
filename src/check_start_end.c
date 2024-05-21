/*
** EPITECH PROJECT, 2024
** finds_values
** File description:
** in file
*/

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_macro.h"
#include "my.h"

int finds_values(char **str, int *i, room_t **robot_info, char *ref)
{
    char **words = NULL;

    if (!str[*i])
        return 1;
    words = my_str_to_word_array(str[*i], ' ');
    if (is_room(words, robot_info, ref) == 84)
        return 1;
    if (!(*robot_info)->next)
        return 1;
    return MY_EXIT_SUCCESS;
}

static int nb_strings(char **str)
{
    int i = 0;

    if (!str)
        return -1;
    for (; str[i]; i++);
    return i;
}

static int exist_or_not(char **str, int *i, room_t **robot_info, char *ref)
{
    int nb_w = 0;
    int tmp = *i + 1;
    int nb_string = nb_strings(str);

    if (tmp >= nb_string)
        return 1;
    for (; str[tmp]; tmp++) {
        nb_w = nb_word(str[tmp], ' ');
        if (nb_w == 0)
            return 1;
        if (nb_w >= 3)
            break;
    }
    *i = tmp;
    if (str[*i]) {
        if (finds_values(str, i, robot_info, ref))
            return 1;
        return 2;
    }
    return 0;
}

int find_type(room_t *node, enum room_type_e type)
{
    int value = 0;

    node = node->next;
    if (!node)
        return value;
    for (; node; node = node->next) {
        if (node->room_type == type)
            value++;
    }
    return value;
}

int fill_struct(char **str, int *i, room_t **robot_info, char *ref)
{
    int nb_end = 0;
    int nb_start = 0;
    room_t *tmp_info = *robot_info;

    nb_end = find_type(tmp_info, (enum room_type_e)END);
    nb_start = find_type(tmp_info, (enum room_type_e)START);
    if (my_grep(str[*i], ref)) {
        if (my_strcmp("end", ref) == 0 && nb_end == 1)
                return 3;
        if (my_strcmp("start", ref) == 0 && nb_start == 1)
                return 3;
        return exist_or_not(str, i, robot_info, ref);
    }
    return MY_EXIT_SUCCESS;
}

int check_start_end(char **str, int *i, room_t **robot_info)
{
    int rtrn = 0;

    if (my_grep(str[*i], "##")) {
        if (my_grep(str[*i], "start"))
            rtrn = fill_struct(str, i, robot_info, "start");
        if (my_grep(str[*i], "end"))
            rtrn = fill_struct(str, i, robot_info, "end");
        if (rtrn == 2)
            return 2;
        if (rtrn == 3)
            return 3;
    }
    return MY_EXIT_SUCCESS;
}

int find_start_end(char **str, room_t **robot_info)
{
    int nb_w = 0;
    int rtrn = 0;

    for (int i = 0; str[i] != NULL; i++){
        nb_w = nb_word(str[i], ' ');
        if (nb_w == 1 && my_grep(str[i], "##") == 0)
            continue;
        rtrn = check_start_end(str, &i, robot_info);
        if (rtrn == 2)
            continue;
        if (rtrn == 3)
            return 3;
        if (finds_values(str, &i, robot_info, "default"))
            return 1;
    }
    if (find_type(*robot_info, (enum room_type_e)END) != 1
        || find_type(*robot_info, (enum room_type_e)START != 1))
        return 3;
    return MY_EXIT_SUCCESS;
}
