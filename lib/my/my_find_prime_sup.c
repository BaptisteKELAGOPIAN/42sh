/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** ah
*/

int my_is_prime(int);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1)
        return (nb);
    else
        while (my_is_prime(nb) != 1)
            nb = nb + 1;
    return (nb);
}
