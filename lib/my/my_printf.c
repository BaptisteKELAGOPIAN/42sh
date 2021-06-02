/*
** EPITECH PROJECT, 2020
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include "../../include/my.h"

static print_t func[] = {
    {'c', print_char},
    {'d', print_nbr},
    {'i', print_nbr},
    {'s', print_str},
    {'b', print_binary},
    {'o', print_octal},
    {'x', print_hexa_low},
    {'X', print_hexa_up},
    {'u', print_unsigned_decimal},
    {'p', print_pointeur},
    {'S', print_non_printable}
};

void appel_func(va_list ap, char a)
{
    for (int i = 0; i < 11; i++)
        if (a == func[i].c)
            func[i].ptr(ap);
}

int next_i_is_perrcent(const char *str, int i, va_list ap)
{
    if (str[i] == '%') {
        my_putchar(str[i]);
        i += 1;
    }
    else
    {
        appel_func(ap, str[i]);
    }
    return (i);
}

int my_printf(const char *str, ...)
{
    va_list ap;
    int i = 0;

    va_start(ap, str);
    for (; str[i]; i++) {
        if (str[i] == '%') {
            i += 1;
            next_i_is_perrcent(str, i, ap);
        }
        else
            my_putchar(str[i]);
    }
    va_end(ap);
    return (i);
}