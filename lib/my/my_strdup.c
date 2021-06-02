/*
** EPITECH PROJECT, 2020
** my_minishell
** File description:
** my_strdup.c
*/
#include <stdlib.h>
#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *message = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++)
        message[i] = src[i];
    message[len] = '\0';
    return (message);
}
