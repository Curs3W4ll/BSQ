/*
** EPITECH PROJECT, 2020
** My_compute_square_root
** File description:
** Return square root of number if it's a whole number
*/

int my_compute_square_root(int nb)
{
    if (nb < 1)
        return 0;
    for (long i = 1; i * i <= nb; i++)
        if (i * i == nb)
            return i;
    return 0;
}
