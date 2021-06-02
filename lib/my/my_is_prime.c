/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** ah
*/

int my_while_is_prime(int nb, int i)
{
    while (i < nb) {
        if (nb % i == 0)
            return (0);
        i = i + 1;
    }
}

int my_is_prime(int nb)
{
    int i = 2;

    if (nb <= 1) {
        my_while_is_prime(nb, i);
    }
    return (1);
}
