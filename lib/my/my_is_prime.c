/*
** EPITECH PROJECT, 2020
** My_is_prime
** File description:
** Return 1 if a number is prime
*/

int my_is_prime(int nb)
{
    if (nb < 2)
        return 0;
    for (int i = 2; i < nb; i++)
        if (nb % i == 0)
            return 0;
    return 1;
}
