/*
** EPITECH PROJECT, 2020
** bs_minishell
** File description:
** step4.c
*/

#include "include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *exec_path(char_list *env, char *str)
{
    char **path;
    int i = 0;
    char *func;

    if (access(str, F_OK) == 0)
        return (str);
    for (; env && my_strncmp(env->str, "PATH=", 4) != 0; env = env->next);
    path = my_str_to_word_array(&env->str[5], ":");
    for (int j = -1; path[i] && j == -1; i++) {
        func = concat_strings(concat_strings(path[i], "/"), str);
        j = access(func, F_OK);
    }
    return (func);
}

char **change_env(char_list *array_env)
{
    char_list *search_size = array_env;
    char_list *copy = array_env;
    char **new_env;
    int i = 0;
    int j = 0;

    for (; search_size; search_size = search_size->next, i++);
    new_env = malloc(sizeof(char *) * (i + 2));
    copy = array_env;
    for (; copy; copy = copy->next, j++) {
        new_env[j] = copy->str;
    }
    new_env[j + 1] = NULL;
    return (new_env);
}

void setenv_unsetenv(char **array, char_list *arr_env, char **env)
{
    if (my_strcmp(array[0], "cd") == 0)
        process_cd(&arr_env, array);
    if (my_strcmp(array[0], "setenv") == 0)
        my_setenv(&arr_env, array);
    if (my_strcmp(array[0], "unsetenv") == 0)
        my_unsetenv(&arr_env, array);
    env = change_env(arr_env);
    return (step4(arr_env, env));
}

char **start_env(void)
{
    char **env = malloc(sizeof(char *) * (3));
    char pwd[1024];

    env[0] = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin: \
/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
    env[1] = concat_strings("PWD=", getcwd(pwd, sizeof(pwd)));
    env[2] = "OLDPWD=";
    env[3] = "HOME=/home/trystan";
    env[4] = NULL;
    return (env);
}

int main(int argc, char **argv, char **env)
{
    (void) argv;
    char_list *array;

    if (argc != 1)
        return (84);
    if (env[0] == NULL)
        env = start_env();
    array = create_array(env);
    step4(array, env);
    return (0);
}