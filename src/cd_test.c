/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-basile.lamotte
** File description:
** cd_test.c
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/my.h"

void process_cd2(char_list **list)
{
    int path_access = 0;
    char *tmp;

    tmp = go_home(list);
    if ((path_access = acces(tmp)) == 1) {
        change_dir(tmp, list);
    } else {
        error(4, "cd", NULL);
    }
}

void change_dir(char *path, char_list **list)
{
    char *tmp;
    char *tmp1;
    char *tmp2;

    if ((tmp = getcwd(NULL, 0)) != NULL) {
        tmp1 = "OLDPWD=";
        tmp2 = my_strjoin(tmp1, tmp);
        supp_array_elem(list, "OLDPWD=");
        push_array_elem(list, tmp2);
    }
    chdir(path);
    if ((tmp = getcwd(NULL, 0)) != NULL) {
        tmp1 = "PWD=";
        put_endler(tmp);
        tmp2 = my_strjoin(tmp1, tmp);
        supp_array_elem(list, "PWD=");
        push_array_elem(list, tmp2);
    }
}

int push_array_elem(char_list **arr, char *str)
{
    char_list *elem = list_init(elem);
    char_list *head = (*arr);
    char_list *prev = NULL;

    elem->str = my_strdup(str);
    while (list_empty(arr)) {
        (*arr) = elem;
        return (0);
    }
    while ((*arr) != NULL) {
        prev = (*arr);
        (*arr) = (*arr)->next;
    }
    if (prev) {
        prev->next = elem;
    } else {
        head = elem;
    }
    elem->next = (*arr);
    (*arr) = head;
    return (0);
}

void put_endler(char const *s)
{
    int i = 0;

    while (s[i] != '\0') {
        my_putchar(s[i]);
        i++;
    }
    my_putchar('\n');
}

int list_empty(char_list **arr)
{
    if ((*arr) == NULL)
        return (1);
    else
        return (0);
}