/*
** EPITECH PROJECT, 2020
** decimal to base
** File description:
** decimal_to_base.c
*/

#include <stdlib.h>
#include "../../include/my.h"
#include <stdio.h>

int for_decimal_to_other_base_unsigned(unsigned int n, int a, int cpt)
{
    for (int j = 0; n != 0; j++) {
        n = n / a;
        cpt += 1;
        }
    return (cpt);
}

char *decimal_to_other_base_unsigned(char *base, unsigned int n)
{
    char *str;
    int a = my_strlen(base);
    int i = 0;
    int cpt = 0;
    unsigned int cpy_n = n;

    cpt = for_decimal_to_other_base_unsigned(n, a, cpt);
    str = malloc(sizeof(char) * (cpt + 1));
    n = cpy_n;
    for (; n != 0; i++) {
        str[i] = base[n % a];
        n = n / a;
    }
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}

int for_decimal_to_other_base_long(unsigned long int n, int a, int cpt)
{
    for (int j = 0; n != 0; j++) {
        n = n / a;
        cpt += 1;
    }
    return (cpt);
}

char *decimal_to_other_base_long(char *base, unsigned long int n)
{
    char *str;
    int a = my_strlen(base);
    int i = 0;
    int cpt = 0;
    unsigned long int cpy_n = n;

    cpt = for_decimal_to_other_base_long(n, a, cpt);
    str = malloc(sizeof(char) * (cpt + 1));
    n = cpy_n;
    for (; n != 0; i++) {
        str[i] = base[n % a];
        n = n / a;
    }
    str[i + 1] = '\0';
    str = my_revstr(str);
    return (str);
}