/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_arg.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdio.h>

void print_char(va_list ap)
{
    char c = va_arg(ap, int);
    my_putchar(c);
}

void print_nbr(va_list ap)
{
    int i = va_arg(ap, int);
    my_put_nbr(i);
}

void print_str(va_list ap)
{
    char *str = va_arg(ap, char *);
    my_putstr(str);
}

void print_binary(va_list ap)
{
    char *base = "01";
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = decimal_to_other_base_unsigned(base, nb);

    if (nb == 0)
        my_putchar('0');
    else
        my_putstr(str);
}

void print_octal(va_list ap)
{
    char *base = "01234567";
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = decimal_to_other_base_unsigned(base, nb);

    if (nb == 0)
        my_putchar('0');
    else
        my_putstr(str);
}