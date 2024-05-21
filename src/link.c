/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include <stdlib.h>
#include "my.h"
#include "my_printf.h"

link_t *create_link(char *name)
{
    link_t *link = malloc(sizeof(link_t));

    link->name = name;
    link->dist = -1;
    link->type = DEFAULT;
    link->next = malloc(sizeof(link_t *) * (1));
    link->next[0] = NULL;
    return link;
}

int get_nbr_connection(link_t *link)
{
    int nbr = 0;

    for (nbr = 0; link->next[nbr] != NULL; nbr++);
    return nbr;
}

static int list_len(link_t **list)
{
    int nbr = 0;

    for (nbr = 0; list[nbr] != NULL; nbr++);
    return nbr;
}

static void add_link_to_array(link_t ***list, link_t *link)
{
    link_t **base_list = *list;
    link_t **new_list = malloc(sizeof(link_t *) * (list_len(base_list) + 2));
    int i = 0;

    for (i = 0; base_list[i] != NULL; i++)
        new_list[i] = base_list[i];
    new_list[i] = link;
    new_list[i + 1] = NULL;
    *list = new_list;
    free(base_list);
}

void connect_links(link_t *link1, link_t *link2)
{
    for (int i = 0; link1->next[i] != NULL; i++)
        if (link1->next[i] == link2)
            return;
    add_link_to_array(&(link1->next), link2);
    add_link_to_array(&(link2->next), link1);
}

void print_link(link_t *link)
{
    my_printf("name: %s, dist: %d, type %d\n",
        link->name, link->dist, link->type);
}

void print_link_connection(link_t *link)
{
    for (int i = 0; link->next[i] != NULL; i++)
        print_link(link->next[i]);
}
