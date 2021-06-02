/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_print_arg2.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include <stdio.h>

void print_hexa_low(va_list ap)
{
    char *base = "0123456789abcdef";
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = decimal_to_other_base_unsigned(base, nb);

    if (nb == 0)
        my_putchar('0');
    else
        my_putstr(str);
}

void print_hexa_up(va_list ap)
{
    char *base = "0123456789ABCDEF";
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = decimal_to_other_base_unsigned(base, nb);

    if (nb == 0)
        my_putchar('0');
    else
        my_putstr(str);
}

void print_unsigned_decimal(va_list ap)
{
    char *base = "0123456789";
    unsigned int nb = va_arg(ap, unsigned int);
    char *str = decimal_to_other_base_unsigned(base, nb);

    if (nb == 0)
        my_putchar('0');
    else
        my_putstr(str);
}

void print_pointeur(va_list ap)
{
    char *base = "0123456789abcdef";
    unsigned long int nb = va_arg(ap, unsigned long int);
    char *str = decimal_to_other_base_long(base, nb);

    if (str == NULL)
        return;
    else {
        my_putchar('0');
        my_putchar('x');
        my_putstr(str);
    }
}