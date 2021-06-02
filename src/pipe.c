/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-42sh-basile.lamotte
** File description:
** pipe
*/

#include "../include/my.h"

void exec_file(char_list *arr_env, char *fun, char **args, char **env)
{
    fun = exec_path(arr_env, args[0]);
    execve(fun, args, env);
    die("ERROR execve second command");
}

char **create_the_file(int nbytes, char *foo, char **array, int i)
{
    int compt = 0;
    char **tmp = malloc(sizeof(array));
    for (int x = 0; array[x+1]; ++x)
        tmp[x] = malloc(sizeof(array[x]));
    FILE *fp = fopen("arg.txt", "w");
    fprintf(fp, "%.*s", nbytes, foo);
    fclose (fp);
    for (i += 1; array[i]; ++i) {
        if (!strcmp("|", array[i]))
            break;
        tmp[compt++] = array[i];
    }
    tmp[compt] = "arg.txt";
    tmp[compt+1] = NULL;
    return (tmp);
}

char **get_piped_arg(char **array, int i)
{
    int w = 0;
    int compt = 0;
    char **tmp = malloc(sizeof(array));
    for (int x = 0; array[x+1]; ++x)
        tmp[x] = malloc(sizeof(array[x]));
    for (w = i-1; w > 0; --w) {
        if (!strcmp("|", array[w]))
            break;
    }
    for (; array[w]; w++) {
        if (!strcmp("|", array[w]))
            break;
        tmp[compt++] = array[w];
    }
    tmp[compt] = NULL;
    return (tmp);
}

void exec_pipe(char_list *arr_env, pipe_t pope, int i)
{
    int link[2];
    pid_t pid;
    char foo[4096];
    char **args = get_piped_arg(pope.array, i);

    if (pipe(link) == -1)
        die("ERROR pipe");
    if ((pid = fork()) == -1)
        die("ERROR fork");
    if (pid == 0) {
        dup2(link[1], 1);
        close(link[0]);
        close(link[1]);
        execve(pope.fun, args, pope.env);
        die("ERROR execve");
    } else {
        close(link[1]);
        int nbytes = read(link[0], foo, sizeof(foo));
        char **tmp = create_the_file(nbytes, foo, pope.array, i);
        exec_file(arr_env, pope.fun, tmp, pope.env);
    }
}

int detect_pipe(char_list *arr_env, char *fun, char **array, char **env)
{
    pipe_t pope;
    pope.array = array;
    pope.fun = fun;
    pope.env = env;
    for (int i = 0; array[i]; ++i) {
        if (!strcmp(array[i], "|")) {
            exec_pipe(arr_env, pope, i);

            return 1;
        }
    }
    return 0;
}