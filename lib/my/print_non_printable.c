/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-trystan.lescoat
** File description:
** print_non_printable.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *add_0(char *str)
{
    int len = my_strlen(str);
    char *str_2 = malloc(sizeof(char) * 4);

    for (int i = 3; i > 0; i--) {
        if (len == 0)
            str_2[i] = '0';
        else {
            str_2[i] = str[len - 1];
            len -= 1;
        }
    }
    str_2[0] = '\\';
    return (str_2);
}

void print_non_printable(va_list ap)
{
    char *base = "01234567";
    char *str = va_arg(ap, char *);
    char *str_2;

    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            str_2 = decimal_to_other_base_unsigned(base, str[i]);
            str_2 = add_0(str_2);
            my_putstr(str_2);
        }
        else
            my_putchar(str[i]);
    }
}