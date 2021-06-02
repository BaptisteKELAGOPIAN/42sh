/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** ah
*/

void my_putchar(char);

int my_strlen(char const * str)
{
    int len = 0;

    for (len; str[len]; len++);
    return (len);
}
