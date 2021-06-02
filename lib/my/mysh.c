/*
** EPITECH PROJECT, 2020
** my_minishell
** File description:
** myls.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int my_strlen_array(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return (i);
}

char **my_read(void)
{
    char *line = NULL;
    size_t len = 0;
    char **array = NULL;

    if (isatty(STDIN_FILENO) == 1)
        my_printf("$> ");
    while (getline(&line, &len, stdin) != -1) {
        if (line != NULL) {
            array = my_str_to_word_array(line, " \n\t");
            return (array);
        }
    }
    return (array);
}

int sep_cmp(const char *str, int i, const char *sep)
{
    for (int j = 0; sep[j]; j++){
        if (str[i] == sep[j])
            return (1);
    }
    return (0);
}

void my_setenv(char_list **array_env, char **array)
{
    char *str = concat_strings(array[1], "=");
    char_list *copy = (*array_env);

    if (array[1] && my_str_isalpha_sh(array[1]) == 0) {
        my_printf("Variable name must contain alphanumeric characters.\n");
        return;
    }
    if (my_strlen_array(array) > 3) {
        my_printf("setenv: Too many arguments.\n");
        return;
    }
    if (array[1]) {
        if (array[2])
            str = concat_strings(str, array[2]);
        char_list_push_back(array_env, str);
    }
    else
        for (;copy; copy = copy->next)
            my_printf("%s\n", copy->str);
    return;
}

void my_unsetenv(char_list **array_env, char **array)
{
    char_list *cp = (*array_env);
    char *str;

    if (my_strlen_array(array) == 1) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    for (int i = 1; array[i]; i++) {
        cp = (*array_env);
        str = concat_strings(array[i], "=\0");
        for (; cp->next && my_strcmp(cp->next->str, str) != 0; cp = cp->next);
        if (cp->next)
            cp->next = cp->next->next;
    }
    return;
}