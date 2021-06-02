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

char **temparray(char **array, int *i)
{
    char **finalarray = malloc(500);

    for (; array[*i] != NULL; *i += 1) {
        if (array[*i][0] == '>')
            break;
        else {
            finalarray[*i] = malloc(500);
            strcpy(finalarray[*i], array[*i]);
        }
    }
    return (finalarray);
}

int temp(char *func, char **array, char **env)
{
    int i = 0;
    char **finalarray = temparray(array, &i);
    int fd = 0;

    fd = open(array[i+1], O_RDONLY);
    if (fd == -1 || array[i][1] != '>')
        fopen(array[i + 1], "w");
    int tempout = open(array[i + 1], 1);
    int oldout = dup(1);
    close(1);
    int newout = dup(tempout);
    execve(func, finalarray, env);
    close(tempout);
    close(1);
    newout = dup(oldout);
    close(oldout);
    return (0);
}