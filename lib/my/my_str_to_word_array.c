/*
** EPITECH PROJECT, 2024
** mini
** File description:
** shell
*/

#include <stddef.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>


int nb_word(char *str, char ref)
{
    int nb = 0;
    int i = 0;

    if (!str)
        return 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != ref && str[i + 1] == ref)
            nb++;
        if (str[i] != ref && str[i + 1] == '\0')
            nb++;
    }
    return nb;
}

char **fil_str(char ref, char **new, int nbw, char *str)
{
    int fil = 0;
    int cpt = 0;
    int save = 0;

    for (int i = 0; i < nbw; i++) {
        for (; str[fil] == ref && str[fil] != '\0'; fil++);
        for (int tmp = fil; str[tmp] != ref && str[tmp] != '\0'; tmp++)
            cpt++;
        new[i] = malloc(sizeof(char) * (cpt + 1));
        new[i][cpt] = '\0';
        save = fil;
        for (int bis = 0; bis < cpt; bis++) {
            new[i][bis] = str[save];
            save++;
        }
        save = 0;
        fil = cpt + fil;
        cpt = 0;
    }
    return new;
}

char **my_str_to_word_array(char *str, char ref)
{
    int nbw = nb_word(str, ref);
    char **new = NULL;

    if (nbw == 0)
        return NULL;
    new = malloc(sizeof(char *) * (nbw + 1));
    new = fil_str(ref, new, nbw, str);
    new[nbw] = NULL;
    return new;
}
