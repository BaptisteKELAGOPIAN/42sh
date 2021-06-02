/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** ah
*/

#include <stdio.h>

int my_strlen(char const * str);

char *my_revstr(char *str)
{
    char temp;
    int length = my_strlen(str);

    for (int i = 0 ; i < length - 1 ; i++) {
        temp = str[i];
        str[i] = str[length - 1];
        str[length - 1] = temp;
        length -= 1;
    }
    return (str);
}
