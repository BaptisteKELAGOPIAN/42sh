/*
** EPITECH PROJECT, 2021
** Code_Sig_Catch
** File description:
** sig_catch
*/
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/my.h"

void sig_catch(int sig)
{
    int sig_return;

    if (WIFSIGNALED(sig) == true) {
        sig_return = WTERMSIG(sig);
        if (sig_return == SIGSEGV)
            my_printf("Segmentation fault");
        if (sig_return == SIGFPE)
            my_printf("Floating exception");
        if (WCOREDUMP(sig))
            my_printf("(core dumped)");
        my_printf("\n");
    }
}

char *concat_strings(char *dest, char const *src)
{
    int i = 0;
    char *str;

    if (dest == NULL)
        return (my_strdup(src));
    str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    for (; dest[i];i++)
        str[i] = dest[i];
    for (int j = 0; src[j]; j++, i++)
        str[i] = src[j];
    str[i] = '\0';
    return (str);
}

void do_exec(char *func, char_list *arr_env, char **array, char **env)
{
    int size = 0;

    for (size = 0; array[size]; size++);
    func = exec_path(arr_env, array[0]);
    env = change_env(arr_env);
    for (int i = 0; array[i] != NULL; i += 1) {
        if (array[i][0] == '>') {
            temp(func, array, env);
            return;
        }
    }
    if (detect_pipe(arr_env, func, array, env));
    else if (execve(func, array, env) == -1) {
        my_printf("%s: Command not found.\n", array[size - 1]);
    }
}

void step4(char_list *arr_env, char **env)
{
    int pid;
    int wstatus;
    char **array = my_read();
    char *func = NULL;
    int cmp;

    if (array && array[0] && my_strcmp(array[0], "exit")) {
        cmp = my_strcmp(array[0], "setenv");
        if (cmp == 0 || my_strcmp(array[0], \
        "unsetenv") == 0 || my_strcmp(array[0], "cd") == 0)
            return (setenv_unsetenv(array, arr_env, env));
        pid = fork();
        if (pid == 0)
            do_exec(func, arr_env, array, env);
        else {
            waitpid(pid, &wstatus, 0);
            sig_catch(wstatus);
            return (step4(arr_env, env));
        }
    } else if (isatty(STDIN_FILENO) == 1)
        my_printf("exit\n");
}