/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-basile.lamotte
** File description:
** third_part_cd.c
*/
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "../include/my.h"

int check_old_pwd(char_list **list)
{
    char_list *head;
    int i = 0;

    head = (*list);
    while ((*list) != NULL) {
        if (my_strncmp((*list)->str, "OLDPWD=", 7) == 0)
            i++;
        (*list) = (*list)->next;
    }
    (*list) = head;
    if (i == 0) {
        return (0);
    } else {
        return (1);
    }
}

void process_tild(char_list **list, char *tmp)
{
    int path_access;

    path_access = 0;
    if (check_old_pwd(list) == 0) {
        add_old_pwd(list);
    }
    if ((path_access = acces(tmp)) == 1) {
        change_dir(tmp, list);
    } else {
        error(4, "cd", NULL);
    }
}

char *new_malloc(size_t size)
{
    char *ret;

    if (!(ret = (char *)malloc(sizeof(*ret) * (size + 1)))) {
        return (NULL);
    }
    return (ret);
}

char *sub_str(char const *s, unsigned int start, size_t len)
{
    char *ret = NULL;
    unsigned int i;

    if (s) {
        if ((ret = new_malloc(len + 1)) == NULL) {
            return (NULL);
        }
        i = -1;
        while (++i < len) {
            ret[i] = s[start + i];
        }
        ret[i] = '\0';
        return (ret);
    }
    return (NULL);
}

int acces(char *path)
{
    int ret_access = access(path, F_OK);

    if (ret_access == 0) {
        if (access(path, X_OK) == 0) {
            return (1);
        } else {
            return (0);
        }
    } else {
        return (0);
    }
}