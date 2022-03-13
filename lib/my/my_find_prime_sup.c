/*
** EPITECH PROJECT, 2020
** My_find_prime_sup
** File description:
** Return the next prime number
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int the_prime = 0;

    if (nb < 2)
        return 2;
    else {
        while (my_is_prime(nb) == 0)
            nb = nb + 1;
        return nb;
    }
    return 0;
}
