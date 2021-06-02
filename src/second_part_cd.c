/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-basile.lamotte
** File description:
** second_part_cd.c
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/my.h"

void go_path(char_list **list, char **tab)
{
    int path_access = 0;

    if (check_old_pwd(list) == 0) {
        add_old_pwd(list);
    }
    if ((path_access = acces(tab[1])) == 1) {
        change_dir(tab[1], list);
    } else {
        error(1, tab[0], tab[1]);
    }
}

void add_old_pwd(char_list **list)
{
    char *tmp;
    char *tmp1 = "OLDPWD=";
    char *tmp2 = NULL;

    if ((tmp = getcwd(NULL, 0)) != NULL) {
        tmp2 = my_strjoin(tmp1, tmp);
        push_array_elem(list, tmp2);
    }
}

char *go_old_pwd(char_list **list)
{
    char_list *head;
    char *tmp;
    size_t i = 0;

    head = (*list);
    tmp = NULL;
    while (head != NULL) {
        if (my_strncmp(head->str, "OLDPWD=", 7) == 0) {
            i = my_strlen(head->str);
            tmp = sub_str(head->str, 7, i);
        }
        head = head->next;
    }
    return (tmp);
}

char *go_home(char_list **list)
{
    char_list *head;
    char *tmp;
    size_t i = 0;

    head = (*list);
    tmp = NULL;
    while (head != NULL) {
        if (my_strncmp(head->str, "HOME=", 5) == 0) {
            i = my_strlen(head->str);
            tmp = sub_str(head->str, 5, i);
        }
        head = head->next;
    }
    return (tmp);
}

void process_cd(char_list **list, char **array)
{
    char *tmp = go_home(list);
    char *tmp2 = go_old_pwd(list);

    if (array[1] != NULL)
    {
        if (array[1][0] == '~')
            process_tild(list, tmp);
        else if (array[1][0] == '-') {
            if (check_old_pwd(list) != 0) {
                change_dir(tmp2, list);
            } else {
                error(3, "cd", NULL);
            }
        } else
            go_path(list, array);
    } else
        process_cd2(list);
}