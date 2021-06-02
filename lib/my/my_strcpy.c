/*
** EPITECH PROJECT, 2020
** B-BOO-101-MPL-1-1-phoenixd02-trystan.lescoat
** File description:
** my_strcpy.c
*/
#include <stdio.h>

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    for (; src[i]; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}