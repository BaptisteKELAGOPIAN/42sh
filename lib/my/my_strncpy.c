/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** ah
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != n; i++)
        dest[i] = src[i];
    dest[n] = '\0';
    return (dest);
}
