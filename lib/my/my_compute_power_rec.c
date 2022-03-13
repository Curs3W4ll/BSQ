/*
** EPITECH PROJECT, 2020
** My_compute_power_rec
** File description:
** Return the result of a number by a power
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    else {
        return (nb * my_compute_power_rec(nb, p - 1));
    }
}
