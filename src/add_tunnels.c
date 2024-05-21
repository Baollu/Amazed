/*
** EPITECH PROJECT, 2024
** add
** File description:
** tunnels
*/
#include <stddef.h>
#include <stdlib.h>
#include "my_macro.h"
#include "my.h"

static void free_str(char **words)
{
    for (int tmp = 0; words[tmp]; tmp++)
        free(words[tmp]);
}

static void fill_tunnels(paths_t **tunnels, char **words, char **links)
{
    push_tunnels(links, tunnels);
    free_str(words);
    free_str(links);
}

int add_tunnels(char **str, paths_t **tunnels)
{
    int nbw = 0;
    char **words = NULL;
    char **links = NULL;
    int nb_tunnels = 0;

    my_printf("#tunnels\n");
    for (int i = 0; str[i]; i++){
        nbw = nb_word(str[i], '-');
        if (nbw < 2)
            continue;
        words = my_str_to_word_array(str[i], ' ');
        links = my_str_to_word_array(words[0], '-');
        if (!words || !links)
            return 1;
        nb_tunnels++;
        fill_tunnels(tunnels, words, links);
    }
    if (nb_tunnels < 2)
        return 1;
    return 0;
}
