/*
** EPITECH PROJECT, 2020
** my_antman
** File description:
** my_match.c
*/
#include "../../include/my.h"

int malloc_match(char **array, char *str, int index)
{
    int len = my_strlen(str);

    for (int i = index; array[i]; i++)
        if (my_strncmp(str, array[i], len) == 0)
            return (1);
    return (0);
}

int word_before_match(char **array, char *str, int index)
{
    int len = my_strlen(str);

    for (int i = 0; i < index; i++)
        if (my_strncmp(str, array[i], len) == 0)
            return (1);
    return (0);
}