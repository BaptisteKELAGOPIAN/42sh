/*
** EPITECH PROJECT, 2020
** exo_desk
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

void start_sep(const char *str, int *i, const char *sep)
{
    for (; str[*i]; (*i) += 1)
        if (sep_cmp(str, *i, sep) == 0)
            return;
}

int count_nbr_words(const char *str, const char *sep)
{
    int nbr_words = 0;

    for (int i = 0; str[i]; i++)
        if (sep_cmp(str, i, sep) == 0 && (i == 0 || sep_cmp(str, i - 1, sep)))
            nbr_words += 1;
    return (nbr_words);
}

int len_word(const char *str, int *i, const char *sep)
{
    int len = 0;

    for (; str[*i] && sep_cmp(str, *i, sep) == 0; (*i) += 1)
        len++;
    for (; str[*i] && sep_cmp(str, *i, sep); (*i) += 1);
    return (len);
}

void string_to_array(char **array, const char *str, const char *sep)
{
    int i = 0;
    int x = 0;
    int y = 0;

    start_sep(str, &i, sep);
    while (str[i]) {
        if (sep_cmp(str, i, sep) == 1) {
            array[x][y] = 0;
            x++;
            y = 0;
            start_sep(str, &i, sep);
        } else {
            array[x][y] = str[i];
            y++;
            i++;
        }
    }
    if (sep_cmp(str, i - 1, sep) == 0)
        array[x][y] = 0;
}

char **my_str_to_word_array(const char *str, const char *sep)
{
    char **array;
    int i = 0;
    int nbr_words = 0;

    if (!str)
        return (NULL);
    start_sep(str, &i, sep);
    nbr_words = count_nbr_words(str, sep);
    array = malloc(sizeof(char *) * (nbr_words + 1));
    array[nbr_words] = NULL;
    for (int n = 0; n < nbr_words; n++)
        array[n] = malloc(sizeof(char) * (len_word(str, &i, sep) + 1));
    string_to_array(array, str, sep);
    return (array);
}