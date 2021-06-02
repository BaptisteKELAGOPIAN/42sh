/*
** EPITECH PROJECT, 2020
** my_str_isupper
** File description:
** ah
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 65 || str[i] > 90)
            return (0);
    return (1);
}
