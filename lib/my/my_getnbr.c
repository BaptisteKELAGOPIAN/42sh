/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** ah
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
    int nb = 0;
    int cpt = 0;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            cpt = cpt + 1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++){
        nb = (nb * 10) + (str[i] - 48);
    }
    if (nb <= -2147483648 || nb >= 2147483648)
        return (0);
    if (cpt % 2 == 1)
        nb = nb * (-1);
    return (nb);
}
