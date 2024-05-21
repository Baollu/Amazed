/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** main fonction
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

static int get_nbr_room(room_t *room)
{
    int nbr_room = 0;

    while (room != NULL){
        nbr_room++;
        room = room->next;
    }
    return nbr_room;
}

static link_t **get_links(room_t *room)
{
    link_t **links = malloc(sizeof(link_t *) * (get_nbr_room(room) + 1));
    int i = 0;

    for (i = 0; room != NULL; i++){
        links[i] = create_link(my_strdup(room->room));
        links[i]->type = room->room_type;
        room = room->next;
    }
    links[i] = NULL;
    return links;
}

link_t *get_start(link_t **links)
{
    for (int i = 0; links != NULL; i++)
        if (links[i]->type == START)
            return links[i];
    return NULL;
}

static link_t *get_end(link_t **links)
{
    for (int i = 0; links != NULL; i++)
        if (links[i]->type == END)
            return links[i];
    return NULL;
}

static void explore(link_t *link, int dist)
{
    link->dist = dist;
    dist++;
    for (int i = 0; link->next[i] != NULL; i++)
        if (link->next[i]->dist == -1 || link->next[i]->dist > dist)
            explore(link->next[i], dist);
}

link_t *get_link_from_name(char *name, link_t **links)
{
    for (int i = 0; links[i] != NULL; i++){
        if (my_strcmp(links[i]->name, name) == 0){
            return links[i];
        }
    }
    return NULL;
}

void link_set_next(link_t *link, paths_t *tunnels, link_t **links)
{
    link_t *link_temp = NULL;

    while (tunnels != NULL){
        if (my_strcmp(tunnels->path1, link->name) == 0)
            link_temp = get_link_from_name(tunnels->path2, links);
        if (link_temp != NULL){
            connect_links(link, link_temp);
            link_temp = NULL;
        }
        tunnels = tunnels->next;
    }
}

link_t *get_closest(link_t *link)
{
    link_t *closest = NULL;
    int closest_dist = -1;

    for (int i = 0; link->next[i] != NULL; i++){
        if (closest_dist == -1 || link->next[i]->dist < closest_dist){
            closest = link->next[i];
            closest_dist = closest->dist;
        }
    }
    return closest;
}

void print_shortest_path(room_t *room, paths_t *tunnels)
{
    link_t **links = get_links(room->next);
    link_t *start = get_start(links);
    link_t *end = get_end(links);

    for (int i = 0; links[i] != NULL; i++)
        link_set_next(links[i], tunnels, links);
    explore(end, 0);
    if (start->dist != -1)
        print_path(links, room->nb_robot);
}
