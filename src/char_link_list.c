/*
** EPITECH PROJECT, 2020
** AtelierCode-Minishell1
** File description:
** main.c
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/my.h"

void char_list_push_back(char_list **list, char *str)
{
    char_list *p = malloc(sizeof(char_list));
    char_list *a;

    p->str = str;
    p->next = NULL;
    if (*list == NULL)
        *list = p;
    else {
        for (a = *list; a->next != NULL; a = a->next);
        a->next = p;
    }
}

char_list *create_array(char **env)
{
    char_list *data;

    data = malloc(sizeof(char_list));
    data->str = env[0];
    data->next = NULL;
    for (int i = 1; env[i]; i++)
        char_list_push_back(&data, env[i]);
    return (data) ;
}

void print_list(char_list *data)
{
    for (; data != NULL; data = data->next)
        my_printf("%s\n", data->str);
}