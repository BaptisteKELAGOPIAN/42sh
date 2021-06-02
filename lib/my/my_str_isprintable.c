/*
** EPITECH PROJECT, 2020
** my_isprintable
** File description:
** ah
*/
#include "../../include/my.h"

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0')
        return (1);
    for (int i = 0; str[i]; i++)
        if (str[i] <= 20 || str[i] == 127)
            return (0);
    return (1);
}

int my_isprintable(char c, char *array)
{
    for (int i = 0; array[i]; i++)
        if (c == array[i])
            return (1);
    return (0);
}
