/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** ah
*/

int my_str_isnum(char const *str)
{
    if (str[0] == '\0')
        return (0);
    for (int i = 0; str[i]; i++)
        if (str[i] < 48 || str[i] > 57)
            return (0);
    return (1);
}
