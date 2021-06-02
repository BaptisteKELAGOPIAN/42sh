/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** ah
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] >= 65 && str[i] <= 90)
            str[i] = str[i] + 32;
    return (str);
}
