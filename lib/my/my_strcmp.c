/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** ah
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    if (s1[i] != s2[i])
        return (s1[i] - s2[i]);
    return (0);
}
