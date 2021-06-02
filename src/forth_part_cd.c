/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-basile.lamotte
** File description:
** forth_part_cd.c
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/my.h"

char_list *list_init(char_list *element)
{
    element = (char_list*)malloc(sizeof(char_list));
    if (element == NULL) {
        exit(EXIT_FAILURE);
    }
    element->str = NULL;
    element->next = NULL;
    return (element);
}

void list_free(char_list **arr)
{
    char_list *list = (*arr);
    char_list *tmp;

    while (list) {
        tmp = list->next;
        list = tmp;
    }
    (*arr) = NULL;
}

int supp_array_elem(char_list **arr, char *arg)
{
    char_list *prev = NULL;
    char_list *temp = (*arr);
    size_t i = my_strlen(arg);

    while (temp != NULL && my_strncmp(temp->str, arg, i) == 0) {
        (*arr) = temp->next;
        return (0);
    }
    while (temp != NULL && my_strncmp(temp->str, arg, i) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return (84);
    prev->next = temp->next;
    return (0);
}

char *my_strjoin(char const *s1, char const *s2)
{
    char *ret;

    if (!s1 || !s2) {
        return (NULL);
    }
    if (!(ret = new_malloc(my_strlen(s1) + my_strlen(s2)))) {
        return (NULL);
    }
    my_strcpy(ret, s1);
    my_strcat(ret, s2);
    return (ret);
}

int error(int value, char *bad_cmd, char *bad_flag)
{
    (void) bad_flag;
    (void) bad_cmd;
    if (value == 1)
        return (84);
    return (0);
}