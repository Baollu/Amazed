/*
** EPITECH PROJECT, 2024
** return
** File description:
** nb of elements
*/

int nb_of_pointers(char **str)
{
    int i = 0;

    if (str == 0)
        return -1;
    for (; str[i] != 0; i++);
    return i;
}
