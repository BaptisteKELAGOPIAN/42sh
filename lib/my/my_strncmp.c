/*
** EPITECH PROJECT, 2020
** B-BOO-101-MPL-1-1-phoenixd02-trystan.lescoat
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; i < n && s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (i == n)
        i--;
    if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
    return (0);
}