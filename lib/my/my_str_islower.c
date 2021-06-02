/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** ah
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i]; i++)
        if (str[i] < 97 || str[i] > 122)
            return (0);
    return (1);
}
